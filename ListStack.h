#pragma once
#include <iostream>
#include "StackImplementation.h"
using namespace std;


class Node {
public:
  ValueType value;
  Node* next;
  Node(const ValueType val);
};

class ListStack:public IStackImplementation{
	public: 
		ListStack();
		ListStack(const ValueType *valueArray, const size_t arraySize);
		~ListStack();
	  	 void push(const ValueType& value) override;
		 void pop() override;
		const ValueType& top() const override;
		bool isEmpty() const override;
		size_t size() const override;
	private:
		Node* first;
	
};