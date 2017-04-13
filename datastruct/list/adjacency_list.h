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

using namespace std;

template <class Key, class Value>
class AdjacencyList : public Container {
public:
	typedef typename map< Key, list<Value> >::iterator inner_iterator;
	typedef Iterator<inner_iterator> Iterator;
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

	const Iterator find(Key key) {
		return Iterator(table.find(key));
	}

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
	 * AdjacencyList cann't computer the indegree, because it didn't known the type of Value 
	 */
	virtual int getIndegree(Key key) {
		notSupport("getIndegree(Key key)");
		return 0;
	}

	virtual int getOutdegree(Key key) {
		inner_iterator it = table.find(key);
		if (it != table.end()) {
			return (*it).second.size();
		}

		return 0;
	}

	int getSize() {
		return table.size();
	}

protected:
	map< Key, list<Value> > table;
};

#endif // _LIST_ADJACENCY_LIST_H_

