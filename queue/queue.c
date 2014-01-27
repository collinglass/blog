#include <stdlib.h>
#include <stdio.h>

typedef struct Element {
	void *value;
} Element;

typedef struct Queue {
	int front;
	int back;
	int size;
	struct Element *queue;
} Queue;

void Queue_new( Queue* _queue ) {
	_queue->front = 0;
	_queue->back = 0;
	_queue->size = 10;
	_queue->queue = calloc(_queue->size, sizeof(Element));
	return;
};

void Queue_refresh( Queue* _queue ) {
	_queue->front = 0;
	_queue->back = 0;
	_queue->size = _queue->size / 2;
	_queue->queue = calloc(_queue->size, sizeof(Element));
	return;
};

void push( Queue* _queue, void *_value ) {
	if ( _queue->back >= _queue->size/2 ) {
		_queue->size = _queue->size * 2;
		Element *queue = _queue->queue;
		_queue->queue = calloc(_queue->size, sizeof(Element));
		_queue->queue = queue;
	} else if (  _queue->size > 10 && (_queue->back - _queue->back) < _queue->size/4 ) {
		Element *queue = _queue->queue;
		Queue_refresh(_queue);
		_queue->queue = queue;
	}
	_queue->queue[_queue->back].value = _value;
	_queue->back++;
	return;
};

Element shift( Queue* _queue ) {
	struct Element result = _queue->queue[_queue->front];
	_queue->queue[_queue->front].value = NULL;
	_queue->front++;
	return result;
};

int main() {
	struct Queue queue1;
	Queue_new(&queue1);
	push(&queue1, "Apple Pie and");
	shift(&queue1);
	push(&queue1, "Banana");
	push(&queue1, "Split");

	while ( (queue1.back - queue1.front) != 0 ) {
		Element element = shift(&queue1);
		void *printOut = element.value;
    	printf("%s ", printOut);
    }
    printf("\n");

	return 0;
};

