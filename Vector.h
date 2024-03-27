
#pragma once
#include <iostream>
#include "StackImplementation.h"
using namespace std;
using Value = double;

class VectorStack : public IStackImplementation {
	public:
		VectorStack() = default;
		VectorStack(const VectorStack& vector);
		~VectorStack();
		void AddMem();
		void push(const ValueType& value) override;
		void pop() override; 
		const ValueType& top() const override;
		bool isEmpty() const override;
		size_t size() const override;
	private:
		Value* _data = nullptr;
    	size_t _size = 0;
    	size_t _capacity = 0;
    	float _multiplicativeCoef = 2.0f;
	};