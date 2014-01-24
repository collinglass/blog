// stack.scala

class Stack[T] () {
	var top = 0
	var stack = new Vector[T](0,0,top) 

	def push(_value: T) = {
		stack = stack :+ _value
		top += 1
	}

	def pop() = {
		var result = stack.last
		top -= 1
		stack = stack.slice(0,top)

		result
	}

	def isEmpty:Boolean = {
		stack.isEmpty
	}
}

var stack = new Stack[String]
stack.push("and Apple Pie")
stack.pop
stack.push("Split")
stack.push("Banana")

while ( stack.isEmpty == false ) {
	print(stack.pop() + " ")
}
println("")