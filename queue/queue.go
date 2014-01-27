package main

import (
	"log"
)

type Queue struct {
	back int
	front int
	queue map[int] interface{}
}

func ( _queue *Queue ) push( _element interface{} ) {
	if _queue.queue == nil {
		_queue.queue = make(map[int] interface{})
	} else if len(_queue.queue) <= 0 {
		_queue.front = 0
		_queue.back = 0
	}
	_queue.queue[_queue.back] = _element
	_queue.back++
}

func ( _queue *Queue ) shift() interface{} {
	var result interface{}
	if !_queue.isEmpty() {
		result = _queue.queue[_queue.front]
		delete(_queue.queue, _queue.front)
		_queue.front++
	}
	return result;
}

func ( _queue *Queue ) isEmpty() bool {
	if ( _queue.back - _queue.front ) <= 0 {
		return true
	}
	return false
}

func main() {
	var queue1 Queue
	queue1.push("and Apple Pie")
	queue1.shift()
	queue1.push("Banana")
	queue1.push("Split")

	for !queue1.isEmpty() {
		log.Println(queue1.shift())
	}
}