#include <stdlib.h>
#include <stdio.h>

struct Node {
	void *value;
	struct Node *next;
};

struct LinkedList {
	struct Node *start;
	struct Node *end;
};

void LinkedList_new(struct LinkedList* llist) {
	llist->start = 0;
	llist->end = 0;
	return;
}

void addNode( struct LinkedList *ll, void *_value ) {
	if ( NULL == ll->start ) {
		ll->start = malloc( sizeof(struct Node) );
		ll->end = ll->start;
	} else {
		ll->end->next = malloc( sizeof(struct Node) );
		ll->end = ll->end->next;
	}
	ll->end->value = _value;
	return;
};

void removeNode( struct LinkedList *ll ) {
	if ( NULL != ll->end ) {
		struct Node *temp = ll->start;
		while ( temp->next != ll->end ) {
			temp = temp->next;
		}
		temp->next = NULL;
	}
	return;
};

int main() {
	struct LinkedList llist;
    LinkedList_new(&llist);
    addNode(&llist, "Banana");
    addNode(&llist, "Split");
    addNode(&llist, "and Apple Pie");
    removeNode(&llist);

    struct Node *temp = llist.start;
    while ( temp != NULL ) {
    	printf("%s ", temp->value);
    	temp = temp->next;
    }
    printf("\n");
};




