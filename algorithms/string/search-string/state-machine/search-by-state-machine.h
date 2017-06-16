/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _SEARCH_BY_STATE_MACHINE_H_
#define _SEARCH_BY_STATE_MACHINE_H_

#include <string>

using namespace std;

class StateMachine {
public:
	StateMachine() {
		states = 0;
		stateMachine = 0;
		chars = 0;
		characters = 0;
	}

	~StateMachine() {
		destory();
	}

	void build(string pattern) {
		destory();
		if (pattern.empty()) return;

		int len = pattern.size();
		states = len + 1;

		// init characters
		characters = new char[len];
		for (int i = 0; i < len; i ++) {
			addCharacter(pattern[i]);
		}

		// alloc stateMachine, it's size is states * chars
		stateMachine = new int*[states];
		stateMachine[0] = new int[states * chars];
		for (int i = 1; i < states; i ++) {
			stateMachine[i] = stateMachine[i-1] + chars;
		}

		// init stateMachine
		for (int i = 0; i < states; i ++) {
			for (int j = 0; j < chars; j ++) {
				// current path
				string p = pattern.substr(0, i) + characters[j];
				for (int k = i + 1; k >= 0; k --) {
					// compute next state
					string pk = pattern.substr(0, k);
					string c = p.substr(i-k+1, k);
					if (pk == c) {
						stateMachine[i][j] = k;
						break;
					}
				}
			}
		}
	}

	int nextState(int state, char c) {
		if (!characters) return 0;
		return stateMachine[state][index(c)];
	}

	void print() {
		printf("  ");
		for (int i = 0; i < chars; i ++) {
			printf("%c ", characters[i]);
		}
		printf("\n");

		for (int i = 0; i < states; i ++) {
			printf("%d ", i);

			for (int j = 0; j < chars; j ++) {
				printf("%d ", stateMachine[i][j]);
			}

			printf("\n");
		}
	}

private:
	int index(char c) {
		if (!characters) return 0;

		for (int i = 0; i < chars; i++) {
			if (characters[i] == c) {
				return i;
			}
		}

		return -1;
	}

	void addCharacter(char c) {
		if (index(c) == -1) {
			characters[chars++] = c;
		}
	}

	void destory() {
		if (stateMachine) {
			delete []stateMachine[0];
			delete []stateMachine;
			stateMachine = 0;
		}

		if (characters) {
			delete []characters;
			characters = 0;
		}

		states = 0;
		chars = 0;
	}

private:
	int states;
	int** stateMachine;
	int chars;
	char* characters;
};

class SearchString {
public:
	static int[] search(string str, StateMachine sm) {
		
	}
};

#endif // _SEARCH_BY_STATE_MACHINE_H_
