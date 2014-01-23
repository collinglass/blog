// linkedlist.scala

class Node[T](_value: T) {
	var value = _value
	var next : Node[T] = _;
}

class LinkedList[T] {
	var start : Node[T] = _;
	var end : Node[T] = _;
	def addNode(_value: T) = { 
		if ( start == null ) {
			start = new Node[T](_value)
			end = start
		} else {
			end.next = new Node[T](_value)
			end = end.next
		}
	}
	def removeNode() = { 
		if ( end != null ) {
			var temp : Node[T] = start
			while ( temp.next != end ) {
				temp = temp.next
			}
			temp.next = null
		}
	}
}

var llist = new LinkedList[String]
llist.addNode("Banana")
llist.addNode("Split")
llist.addNode("and Apple Pie")
llist.removeNode()

var node = llist.start
while ( node != null ) {
	print(node.value + " ")
	node = node.next
}
println("")
