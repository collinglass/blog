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

	this.removeNode = function( ) {
		if ( this.end ) {
			var temp = this.start;
			while ( this.end != temp.next ) {
				temp = temp.next;
			}
			temp.next = null;
		};
	};
};

var list = new LinkedList();
list.addNode("Banana");
list.addNode("Split");
list.addNode("and Apple");
list.removeNode();

document.getElementById("results").innerHTML = list.start.value + ' ' + list.start.next.value;
