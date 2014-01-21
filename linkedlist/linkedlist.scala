// linkedlist.scala

class Node[T](_value: T) {
	var value = _value
	var next : Node[T] = _;
}

class LinkedList[T] {
	var start : Node[T] = _;
	var end : Node[T] = _;
	def addNode(_value: T) : Node[T] = { 
		if ( start == null ) {
			start = new Node[T](_value)
			end = start
		} else {
			end.next = new Node[T](_value)
			end = end.next
		}
		new Node[T](_value)
	}
}

var llist = new LinkedList[String]
llist.addNode("Banana")
llist.addNode("Split")

println(llist.start.value + " " + llist.start.next.value)
