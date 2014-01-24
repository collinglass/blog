function Stack() {
	var stack = [];
	var top = 0;

	this.push = function( _element ) {
		stack.splice(top, 0, _element);
		top++;
	};
	this.pop = function () {
		if ( !this.isEmpty() ) {
			top--;
			var result = stack[top];
			stack.splice(top);
			return result;
		}
	};
	this.isEmpty = function () {
		if (stack.length <= 0)
			return true;
		return false;
	}
};

var stack1 = new Stack();

stack1.push("And Apple Pie")
stack1.pop();
stack1.push("Split");
stack1.push("Banana");

while ( !stack1.isEmpty() ) {
	document.getElementById("results").innerHTML += (stack1.pop() + " ");
};
