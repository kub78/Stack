#include "ListStack.h"
#include <iostream>
#include "StackImplementation.h"

Node::Node(const ValueType val) {
	this->value = val;
	this->next = NULL;
}

ListStack::ListStack() {
	first = NULL;
}

ListStack::~ListStack() {
	while (first != NULL) {
		pop();
	}
}


void ListStack::push(const ValueType& val) {
	Node* elem = new Node(val);
	elem->next = first;
	first = elem;
}

void ListStack::pop() {
	if (isEmpty()) {
		return;
	}
	Node* elem = first;
	first = elem->next;
	delete elem;
}

const ValueType &ListStack::top() const {
  if (isEmpty()) {
    throw std::runtime_error("Пусто");
  }
  return first->value;
}

bool ListStack::isEmpty() const{
	if (first == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

size_t ListStack::size() const{
	int kol = 0;
	if (isEmpty()) {
		return kol;
	}
	Node* elem = first;
	while (elem != nullptr) {
		kol++;
		elem = elem->next;
	}
	return kol;
}
