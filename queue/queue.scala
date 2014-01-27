// queue.scala

class Queue[T] () {
	var front = 0
	var queue = new Vector[T](0,0,front) 

	def push(_value: T) = {
		queue = queue :+ _value
		front += 1
	}

	def shift() = {
		var result = queue.apply(0)
		queue = queue.slice(1,front)
		front -= 1

		result
	}

	def isEmpty:Boolean = {
		queue.isEmpty
	}
}

var queue = new Queue[String]
queue.push("Apple Pie and")
queue.push("Banana")
queue.push("Split")
queue.shift

while ( queue.isEmpty == false ) {
	print(queue.shift() + " ")
}
println("")