function Node() {
	"use strict";
	var value = null;
	var leftchild = null;
	var rightchild = null;
	var parent = null;
}

function BinaryTree() {
	"use strict";
	this.root = null;

	this.makeNode = function() {
		var node = new Node();
		return node;
	};
	this.insert = function( _value ) {
		if ( !this.root ) {
			this.root = this.makeNode();
			this.root.value = _value;
			return true;
		} else {
			var parent = this.root;
			var node = this.root;
			while ( node ) {
				if ( node.value >= _value ) {
					parent = node;
					node = node.leftchild;
				} else {
					parent = node;
					node = node.rightchild;
				}
			}
			node = this.makeNode();
			node.value = _value;
			if ( node.value <= parent.value ) {
				parent.leftchild = node;
				node.parent = parent;
				return true;
			} else {
				parent.rightchild = node;
				node.parent = parent;
				return true;
			}
		}
		return false;
	};

	this.remove = function( _value ) {
		var parent = this.root;
		var node = this.root;
		while ( node ) {
			if ( node.value > _value ) {
				parent = node;
				node = node.leftchild;
			} else if (node.value < _value) {
				parent = node;
				node = node.rightchild;
			} else {
				if ( node === parent.leftchild ) {
					if ( !node.leftchild && !node.rightchild ) {
						delete parent.leftchild;
						return true;
					} else if ( node.leftchild && !node.rightchild ) {
						parent.leftchild = node.leftchild;
						return true;
					} else if ( !node.leftchild && node.rightchild ) {
						parent.leftchild = node.rightchild;
						return true;
					} else {
						var temp = this.minNode(node.rightchild);
						parent.leftchild.value = temp.value;
						if ( temp === temp.parent.leftchild ) {
							temp.parent.leftchild = null;
						} else {
							temp.parent.rightchild = null;
						}
						return true;
					}
				} else {
					if ( !node.leftchild && !node.rightchild ) {
						delete parent.rightchild;
						return true;
					} else if ( node.leftchild && !node.rightchild ) {
						parent.rightchild = node.leftchild;
						return true;
					} else if ( !node.leftchild && node.rightchild ) {
						parent.rightchild = node.rightchild;
						return true;
					} else {
						var temp = this.minNode(node.rightchild);
						parent.rightchild.value = temp.value;
						if ( temp === temp.parent.leftchild ) {
							parent.leftchild = null;
						} else {
							parent.rightchild = null;
						}
						return true;
					}
				}
			}
		}
		return false;
	};

	this.minNode = function ( _root ) {
		var result = _root;
		while ( result.leftchild ) {
			result = result.leftchild;
		}
		return result;
	};

	this.has = function( _value ) {
		var node = this.root;
		while ( node ) {
			if ( node.value > _value ) {
				node = node.leftchild;
			} else if (node.value < _value) {
				node = node.rightchild;
			} else {
				return true;
			}
		}
		return false;
	};

}



