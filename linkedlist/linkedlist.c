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

int main() {
	struct LinkedList llist;
    LinkedList_new(&llist);
    addNode(&llist, "Banana");
    addNode(&llist, "Split");

    printf("%s %s\n", llist.start->value, llist.start->next->value);
};