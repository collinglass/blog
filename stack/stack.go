package main

import (
	"log"
)

type Stack struct {
	top int
	stack map[int] interface{}
}

func ( _stack *Stack ) push( _element interface{} ) {
	if _stack.top == 0 {
		_stack.stack = make(map[int] interface{})
	}
	_stack.stack[_stack.top] = _element
	_stack.top++
}

func ( _stack *Stack ) pop() interface{} {
	var result interface{}
	if !_stack.isEmpty() {
		_stack.top--
		result = _stack.stack[_stack.top]
		delete(_stack.stack, _stack.top)
	}
	return result;
}

func ( _stack *Stack ) isEmpty() bool {
	if len(_stack.stack) <= 0 {
		return true
	}
	return false
}

func main() {

	var stack1 Stack
	stack1.push("and Apple Pie")
	stack1.pop()
	stack1.push("Split")
	stack1.push("Banana")

	for !stack1.isEmpty() {
		log.Println(stack1.pop())
	}

}