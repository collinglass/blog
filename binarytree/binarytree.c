#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int value;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

typedef struct {
	Node *root;
} BinaryTree;

typedef enum {
	NOERROR,
	INSERTFAIL,
	REMOVEFAIL
} BT_ERROR;

void newBT( BinaryTree *_bt ) {
	_bt->root = 0;
	return;
};

Node* makeNode(int _value ) {
	Node *node = malloc(sizeof(*node));
	if (node == NULL) {
        return NULL;
    }
	node->value = _value;
	node->left = 0;
	node->right = 0;
	node->parent = 0;
	return node;
};

BT_ERROR insert( BinaryTree* _bt, int _value ) {
	Node *node = _bt->root;
	if ( 0 == node ) {
		_bt->root = makeNode(_value);
		return NOERROR;
	} else {
		Node *parent = _bt->root;
		while ( 0 != node ) {
			if ( node->value >= _value ) {
				parent = node;
				node = node->left;
			} else {
				parent = node;
				node = node->right;
			}
		}
		node = makeNode(_value);
		if ( node->value <= parent->value ) {
			parent->left = node;
			node->parent = parent;
			int display = node->value;
			return NOERROR;
		} else {
			parent->right = node;
			node->parent = parent;
			int display = node->value;
			return NOERROR;
		}
	}
	return INSERTFAIL;
};

Node* minNode( Node* _root ) {
	if ( _root == 0 ) {
		return 0;
	}
	Node* result = _root;
	while ( result->left != 0 ) {
		result = result->left;
	}
	return result;
}

int has( BinaryTree* _bt, int _value ) {
	Node *node = _bt->root;
	while ( 0 != node ) {
		if ( node->value > _value ) {
			node = node->left;
		} else if ( node->value < _value ) {
			node = node->right;
		} else {
			return 1;
		}
	}
	return 0;
}

void removal( BinaryTree* _bt, Node* _parent, Node* _node ) {
	if ( _node == _parent ) {
		if ( _node->left == 0 && _node->right == 0 ) {
			free(_bt->root);
			return;
		} else if ( _node->left != 0 && _node->right == 0 ) {
			_bt->root = _node->left;
			return;
		} else if ( _node->left == 0 && _node->right != 0 ) {
			_bt->root = _node->right;
			return;
		} else {
			Node* temp;
			temp = minNode(_node->right);
			Node* tempParent = temp->parent;
			_bt->root = temp;
			if ( temp == tempParent->left ) {
				free(tempParent->left);
			} else {
				free(tempParent->right);
			}
		}
	} else if ( _node == _parent->left ) {
		if ( _node->left == 0 && _node->right == 0 ) {
			free(_parent->left);
			return;
		} else if ( _node->left != 0 && _node->right == 0 ) {
			_parent->left = _node->left;
			return;
		} else if ( _node->left == 0 && _node->right != 0 ) {
			_parent->left = _node->right;
			return;
		} else {
			Node* temp;
			temp = minNode(_node->right);
			Node* tempParent = _parent->left;
			tempParent->value = temp->value;
			tempParent = temp->parent;
			if ( temp == tempParent->left ) {
				free(tempParent->left);
			} else {
				free(tempParent->right);
			}
		}
	} else {
		if ( _node->left == 0 && _node->right == 0 ) {
			_parent->right = 0;
			return;
		} else if ( _node->left != 0 && _node->right == 0 ) {
			_parent->right = _node->left;
			return;
		} else if ( _node->left == 0 && _node->right != 0 ) {
			_parent->right = _node->right;
			return;
		} else {
			Node* temp;
			temp = minNode(_node->right);
			_node->value = temp->value;
			Node *tempParent = temp->parent;
			if ( temp == tempParent->left ) {
				free(tempParent->left);
			} else {
				free(tempParent->right);
			}
		}
	}
	return;
}

BT_ERROR removeNode( BinaryTree* _bt, int _value ) {
	Node *parent = _bt->root;
	Node *node = _bt->root;
	printf("%d \n", _value);
	while ( node != 0 ) {
		if ( node->value > _value ) {
			parent = node;
			node = node->left;
		} else if ( node->value < _value ) {
			parent = node;
			node = node->right;
		} else {
			removal(_bt, parent, node);
			return NOERROR;
		}
	}
	return REMOVEFAIL;
}

int main () {
	BinaryTree bt;
	newBT(&bt);

	for ( int i = 0 ; i <= 10 ; i++ ) {
		BT_ERROR err = insert(&bt, i);
		if ( err != NOERROR ) {
			printf("%s \n", err);
		}
	}
	for ( int j = 20 ; j > 10 ; j-- ) {
		BT_ERROR err = insert(&bt, j);
		if ( err != NOERROR ) {
			printf("%s \n", err);
		}
	}
	removeNode(&bt, 0);
	removeNode(&bt, 4);
	removeNode(&bt, 14);
	removeNode(&bt, 14);
	for ( int i = 0 ; i <= 20 ; i++ ) {
		printf("%d: %d \n", i, has(&bt, i));
	}
	return 0;
}