#include <stdlib.h>
#include <stdio.h>

typedef struct Element {
	void *value;
} Element;

typedef struct Stack {
	int top;
	int size;
	struct Element *stack;
} Stack;

void Stack_new( Stack* _stack ) {
	_stack->top = 0;
	_stack->size = 10;
	_stack->stack = calloc(_stack->size, sizeof(Element));
	return;
};

void push( Stack* _stack, void *_value ) {
	if ( _stack->top >= _stack->size/2 ) {
		_stack->size = _stack->size * 2;
		Element *stack = _stack->stack;
		_stack->stack = calloc(_stack->size, sizeof(Element));
		_stack->stack = stack;
	}
	_stack->stack[_stack->top].value = _value;
	_stack->top++;
	return;
};

Element pop( Stack* _stack ) {
	_stack->top--;
	struct Element result = _stack->stack[_stack->top];
	_stack->stack[_stack->top].value = NULL;
	return result;
};

int main() {
	struct Stack stack1;
	Stack_new(&stack1);
	push(&stack1, "and Apple Pie");
	pop(&stack1);
	push(&stack1, "Split");
	push(&stack1, "Banana");

	while ( stack1.top != 0 ) {
		Element element = pop(&stack1);
		void *printOut = element.value;
    	printf("%s ", printOut);
    }
    printf("\n");

	return 0;
};








