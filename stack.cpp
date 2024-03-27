#include "Stack.h"
#include "ListStack.h"
#include "Vector.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
{
	if (container == StackContainer::Vector)
	{
		_containerType = StackContainer::Vector;
		_pimpl = static_cast<IStackImplementation* >(new VectorStack());
	}

	else if (container == StackContainer::List)
	{
		_containerType = StackContainer::List;
		_pimpl = static_cast<IStackImplementation* >(new ListStack());
	}
}



Stack::Stack(const ValueType* valueArray, const size_t arraySize,StackContainer container)
{
	if (container == StackContainer::Vector)
	{
		_containerType = StackContainer::Vector;
		_pimpl = static_cast<IStackImplementation* >(new VectorStack());

	}

	else if (container == StackContainer::List)
	{
		_containerType = StackContainer::List;
		_pimpl = static_cast<IStackImplementation* >(new ListStack());
	}
    
	if (arraySize != 0)
	{
		for (size_t i = 0; i < arraySize; ++i)
		{
			_pimpl->push(valueArray[i]);
		}
	}
}

Stack::~Stack(){
    delete _pimpl;
}

Stack::Stack(const Stack &copyStack){
    _containerType = copyStack._containerType;
    if (_pimpl != nullptr){
        delete _pimpl;
    }
    if (_containerType ==  StackContainer::List){
       _pimpl = static_cast<IStackImplementation* >(new ListStack());
   }   
    else if(_containerType ==  StackContainer::Vector){
        _pimpl = static_cast<IStackImplementation* >(new VectorStack());
    }
    size_t size = copyStack.size();
   ValueType* tmp = new ValueType[size];
    int j = 0;
    while (!copyStack.isEmpty()) {
        tmp[j] = copyStack.top();
        copyStack._pimpl->pop();
        j++;
    }
    for (int i = size - 1; i >= 0; i--) {
        copyStack._pimpl->push(tmp[i]);
        _pimpl->push(tmp[i]);
    }
    delete [] tmp;
}

Stack &Stack::operator=(const Stack &copyStack) {
    if (copyStack._pimpl == nullptr || copyStack._pimpl == _pimpl) {
        return *this;
    }
    if (_pimpl != nullptr){
        delete _pimpl;
    }
    _containerType = copyStack._containerType;
	if(_containerType ==  StackContainer::Vector)
    {
        _pimpl = static_cast<IStackImplementation* >(new VectorStack());
    }
    else if (_containerType ==  StackContainer::List)
    {
       _pimpl = static_cast<IStackImplementation* >(new ListStack());
   } 
    size_t size = copyStack.size();
    ValueType* tmp = new ValueType[size];
    int j = 0;
    while (!copyStack.isEmpty()){
        tmp[j] = copyStack.top();
        copyStack._pimpl->pop();
        j++;
    }
    for (int i = size - 1; i >= 0; i--) {
        copyStack._pimpl->push(tmp[i]);
        _pimpl->push(tmp[i]);
    }
    delete [] tmp;
    return *this;
}

void Stack:: push(const ValueType& value){
    _pimpl->push(value);
    
}

void Stack:: pop(){
    _pimpl->pop();
}

const ValueType& Stack:: top() const{
    return _pimpl->top();
}

bool Stack:: isEmpty() const{
    return _pimpl->isEmpty();
}

size_t Stack::size() const{
    return _pimpl->size();
}