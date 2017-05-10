/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */
#ifndef _LOOP_2_RECURSIVE_H_
#define _LOOP_2_RECURSIVE_H_

#include "../../datastruct/queue/stack/stack.h"

class Loop2Recursive {
	static const int EXT = -1;

public:
	/*
	 * addtion 1 to n with loop
	 */
	static int loop(int n) {
		int result = 0;
		Stack<int, 1000> stack;
		stack.push_back(n);
		do {
			int x = stack.get();
			if (x == 1) {
				// condition of return
				stack.push_back(EXT);
			} else if (x == EXT) {  
				// pop EXT
				stack.pop();
				if (stack.getSize() == 0) break;

				result += stack.pop();
				stack.push_back(EXT);
			} else {
				stack.push_back(x - 1);
			}
		} while (true);
		return result;
	}

	/*
	 * addtion 1 to n with recursive
	 */
	static int recursive(int n) {
		if (n <= 1) return 1;

		return recursive(n-1) + n;
	}
};

#endif // _LOOP_2_RECURSIVE_H_
