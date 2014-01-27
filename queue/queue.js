function Queue() {
	var queue = [];
	var size = 0;

	this.push = function( _element ) {
		queue.splice(size, 0, _element);
		size++;
	};
	this.shift = function () {
		if ( !this.isEmpty() ) {
			var result = queue[0];
			queue.splice(0,1);
			size--;
			return result;
		}
	};
	this.isEmpty = function () {
		if (size <= 0)
			return true;
		return false;
	};
};

