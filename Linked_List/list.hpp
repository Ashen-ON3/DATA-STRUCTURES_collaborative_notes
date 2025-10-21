#pragma once
class List {
	public:
		virtual void addFirst(int) = 0;
		virtual void addLast(int) = 0;
		virtual int removeFirst() = 0;
		virtual int removeLast() = 0;
		virtual int get(int pos) = 0;
		virtual void print() = 0;
};