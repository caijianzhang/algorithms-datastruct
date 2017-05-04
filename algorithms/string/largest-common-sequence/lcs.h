/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */
#ifndef _LARGEST_COMMON_SEQUENCE_H_
#define _LARGEST_COMMON_SEQUENCE_H_

#include <string>

using namespace std;

class LCS {
public:
	static string findLargestCommonSequence(string s1, string s2) {
		int size1 = s1.size();
		int size2 = s2.size();
		if (size1 == 0 || size2 == 0) return "";

		if (s1[size1 - 1] == s2[size2 -1]) {
			return findLargestCommonSequence(s1.substr(0, size1 - 1), s2.substr(0, size2 - 1)) + s1[size1 - 1];
		}

		string lcs1 = findLargestCommonSequence(s1.substr(0, size1 - 1), s2);
		string lcs2 = findLargestCommonSequence(s1, s2.substr(0, size2 - 1));
		if (lcs1.size() > lcs2.size()) {
			return lcs1;
		} else {
			return lcs2;
		}
	}
};

#endif // _LARGEST_COMMON_SEQUENCE_H_

