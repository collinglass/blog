function LinkedList() {
	this.makeNode = function() {
		return {value:null, next:null};
	};

	this.start = null;
	this.end = null;
	
	this.addNode = function( value ) {
		if ( !this.start ) {
			this.start = this.makeNode();
			this.end = this.start;
		} else {
			this.end.next = this.makeNode();
			this.end = this.end.next;
		};
		this.end.value = value;
	};
};

var list = new LinkedList();
list.addNode("Hello");
list.addNode("World");

document.getElementById("results").innerHTML = list.start.value + ' ' + list.start.next.value;
