package main

import (
	"log"
)

type Node struct {
	value interface{}
	next *Node
}

type LinkedList struct {
	start *Node
	end *Node
}
	
func (ll *LinkedList) addNode( _value interface{} ) {
	if ll.start == nil {
		ll.start = &Node{value: _value, next:nil}
		ll.end = ll.start
	} else {
		ll.end.next = &Node{value: _value, next:nil}
		ll.end = ll.end.next
	}
}

func main() {
	var llist LinkedList
	llist.addNode("Hello")
	llist.addNode("World")
	log.Println(llist.start.value, llist.start.next.value)
}
