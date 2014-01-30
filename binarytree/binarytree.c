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

void newBT( BinaryTree *bt ) {
	bt->root = 0;
	return;
};

Node* makeNode(int paramValue ) {
	Node *node = malloc(sizeof(*node));
	if (node == NULL) {
        return NULL;
    }
	node->value = paramValue;
	node->left = 0;
	node->right = 0;
	node->parent = 0;
	return node;
};

BT_ERROR insert( BinaryTree* bt, int paramValue ) {
	Node *node = bt->root;
	if ( 0 == node ) {
		bt->root = makeNode(paramValue);
		return NOERROR;
	} else {
		Node *parent = bt->root;
		while ( 0 != node ) {
			if ( node->value >= paramValue ) {
				parent = node;
				node = node->left;
			} else {
				parent = node;
				node = node->right;
			}
		}
		node = makeNode(paramValue);
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

Node* minNode( Node* paramRoot ) {
	if ( paramRoot == 0 ) {
		return 0;
	}
	Node* result = paramRoot;
	while ( result->left != 0 ) {
		result = result->left;
	}
	return result;
}

int has( BinaryTree* bt, int paramValue ) {
	Node *node = bt->root;
	while ( 0 != node ) {
		if ( node->value > paramValue ) {
			node = node->left;
		} else if ( node->value < paramValue ) {
			node = node->right;
		} else {
			return 1;
		}
	}
	return 0;
}

void removal( BinaryTree* bt, Node* paramParent, Node* paramNode ) {
	if ( paramNode == paramParent ) {
		if ( paramNode->left == 0 && paramNode->right == 0 ) {
			free(bt->root);
			return;
		} else if ( paramNode->left != 0 && paramNode->right == 0 ) {
			bt->root = paramNode->left;
			return;
		} else if ( paramNode->left == 0 && paramNode->right != 0 ) {
			bt->root = paramNode->right;
			return;
		} else {
			Node* temp;
			temp = minNode(paramNode->right);
			Node* tempParent = temp->parent;
			bt->root = temp;
			if ( temp == tempParent->left ) {
				free(tempParent->left);
			} else {
				free(tempParent->right);
			}
		}
	} else if ( paramNode == paramParent->left ) {
		if ( paramNode->left == 0 && paramNode->right == 0 ) {
			free(paramParent->left);
			return;
		} else if ( paramNode->left != 0 && paramNode->right == 0 ) {
			paramParent->left = paramNode->left;
			return;
		} else if ( paramNode->left == 0 && paramNode->right != 0 ) {
			paramParent->left = paramNode->right;
			return;
		} else {
			Node* temp;
			temp = minNode(paramNode->right);
			Node* tempParent = paramParent->left;
			tempParent->value = temp->value;
			tempParent = temp->parent;
			if ( temp == tempParent->left ) {
				free(tempParent->left);
			} else {
				free(tempParent->right);
			}
		}
	} else {
		if ( paramNode->left == 0 && paramNode->right == 0 ) {
			paramParent->right = 0;
			return;
		} else if ( paramNode->left != 0 && paramNode->right == 0 ) {
			paramParent->right = paramNode->left;
			return;
		} else if ( paramNode->left == 0 && paramNode->right != 0 ) {
			paramParent->right = paramNode->right;
			return;
		} else {
			Node* temp;
			temp = minNode(paramNode->right);
			paramNode->value = temp->value;
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

BT_ERROR removeNode( BinaryTree* bt, int paramValue ) {
	Node *parent = bt->root;
	Node *node = bt->root;
	printf("%d \n", paramValue);
	while ( node != 0 ) {
		if ( node->value > paramValue ) {
			parent = node;
			node = node->left;
		} else if ( node->value < paramValue ) {
			parent = node;
			node = node->right;
		} else {
			removal(bt, parent, node);
			return NOERROR;
		}
	}
	return REMOVEFAIL;
}

int main () {
	BinaryTree binarytree;
	newBT(&binarytree);

	for ( int i = 0 ; i <= 10 ; i++ ) {
		BT_ERROR err = insert(&binarytree, i);
		if ( err != NOERROR ) {
			printf("%s \n", err);
		}
	}
	for ( int j = 20 ; j > 10 ; j-- ) {
		BT_ERROR err = insert(&binarytree, j);
		if ( err != NOERROR ) {
			printf("%s \n", err);
		}
	}
	removeNode(&binarytree, 0);
	removeNode(&binarytree, 4);
	removeNode(&binarytree, 14);
	removeNode(&binarytree, 14);
	for ( int i = 0 ; i <= 20 ; i++ ) {
		printf("%d: %d \n", i, has(&binarytree, i));
	}
	return 0;
}