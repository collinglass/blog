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

