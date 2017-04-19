/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _LIST_ADJACENCY_LIST_H_
#define _LIST_ADJACENCY_LIST_H_

#include "../container.h"
#include "../iterator.h"
#include <map>
#include <list>
#include <vector>

/*
 * --------------------------------------------------------
 * | key1 | value1 -> value2 -> value3 ......             |
 * --------——----------------------------------------------
 * | key2 | value1 -> value2 -> value3 ......             |
 * --------------------------------------------------------
 * | key3 | value1 -> value2 -> value3 ......             |
 * --------------------------------------------------------
 *
 */

using namespace std;

template <class Key, class Value>
class AdjacencyList : public Container {
public:
	typedef typename map< Key, list<Value> >::iterator inner_iterator;
	typedef Iterator<inner_iterator, true> Iterator;
	typedef list<Value> value_type;
	AdjacencyList() {}
	~AdjacencyList() {}

public:
	virtual const string getClassName() {
		return "AdjacencyList";
	}

	virtual Iterator begin() {
		Iterator it(table.begin());
		return it;
	}

	virtual Iterator end() {
		return Iterator(table.end());
	}

	virtual void put(Key key, Value value) {
		list<Value> l;
		inner_iterator it = table.find(key);
		if (it != table.end())  {
			l = it->second;
			table.erase(it);
		}

		l.push_back(value);
		table.insert(pair< Key, list<Value> >(key, l));
	}

	Iterator find(Key key) {
		return Iterator(table.find(key));
	}

	/*
	 * if the value with key exist
	 */
	bool exist(Key key, Value value) {
		inner_iterator it = table.find(key);
		if (it != table.end()) {
			typename value_type::iterator _it = it->second.begin();
			for (; _it != it->second.end(); ++_it) {
				if (*_it == value) {
					return true;
				}
			}
		}

		return false;
	}

	/*
	 * calculate the count of the value appears
	 */
	int count(Value value) {
		int count = 0;
		inner_iterator it = table.begin();
		for (; it != table.end(); ++it) {
			typename value_type::iterator _it = it->second.begin();
			for (; _it != it->second.end(); ++_it) {
				if (*_it == value) {
					count ++;	
				}
			}
		}

		return count;
	}

	/*
	 * get key set
	 */
	vector<Key> keySet() {
		vector<Key> set;
		inner_iterator it = table.begin();
		for (; it != table.end(); ++it) {
			set.push_back(it->first);
		}

		return set;
	}

	/*
	 * operator []
	 * you can get value by @adjacencylist[@key]
	 */
	value_type operator[](Key key) {
		return table[key];
	}

	/*
	 * get the size 
	 */ 
	int getSize() {
		return table.size();
	}

protected:
	map< Key, list<Value> > table;
};

#endif // _LIST_ADJACENCY_LIST_H_

