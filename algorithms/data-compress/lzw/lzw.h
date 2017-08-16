/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _DATA_COMPRESS_LZW_H_
#define _DATA_COMPRESS_LZW_H_

#include <map>
#include <string>
#include <vector>

using namespace std;

class LZW {
public:
	LZW() {}

	vector<int> compress(string text) {
		vector<int> result;
		init();
		char c = text[0];
		string s = string(1, c);
		for (int i = 1; i < text.length(); i ++) {
			c = text[i];
			string t = s + c;
			map<string, int>::iterator it = indices.find(t);
			if (it != indices.end()) {
				s = t;
			} else {
				it = indices.find(s);
				insert(t);
				s = string(1, c);
				result.push_back(it->second);
			}
		}

		map<string, int>::iterator it = indices.find(s);
		result.push_back(it->second);
		return result;
	}

	string decompress(vector<int> index) {
		string result;
		vector<int>::iterator it = index.begin();
		for (; it != index.end(); ++it) {
			printf("%d is %s\n", *it, get(*it).c_str());
			result += get(*it);
		}

		return result;
	}

private:
	void init() {
		indices.clear();
		dictionary.clear();
		for (int c = 0; c < 256; c++) {
			insert(string(1, c));
		}
	}

	int insert(string s) {
		int index = indices.size();
		indices.insert(pair<string, int>(s, index));
		if (index == dictionary.size()) {
			printf("insert %d -> %s\n", index, s.c_str());
			dictionary.push_back(pair<int, string>(index, s));
		}
		return index;
	}

	string get(int index) {
		return dictionary[index].second;
	}

private:
	map<string, int> indices;
	vector< pair<int, string> > dictionary;
};

#endif // _DATA_COMPRESS_LZW_H_
