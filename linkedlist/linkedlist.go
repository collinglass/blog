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

func (ll *LinkedList) removeNode( ) {
	if ll.end != nil {
		temp := ll.start
		for temp.next != ll.end {
			temp = temp.next
		}
		temp.next = nil
	}
}

func main() {
	var llist LinkedList
	llist.addNode("Banana")
	llist.addNode("Split")
	llist.addNode("and Apple pie")
	llist.removeNode()
	var node = llist.start
	for node != nil {
		log.Print(node.value)
		node = node.next
	}
}
