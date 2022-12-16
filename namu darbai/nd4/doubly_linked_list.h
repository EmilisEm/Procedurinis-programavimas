#ifndef __DOUBLY_LINKED_LIST

#define __DOUBLY_LINKED_LIST

typedef struct Node
{
    void *value;
    size_t valueSize;
    struct Node *prev;
    struct Node *next;
} Node;

// coppies size number of bytes from one location to another
void coppyBytes(void *destination, void *source, size_t size);

// Creates double linked list. If fails returns -1
int initDLList(Node **head, Node **tail, void *value, size_t valueSize);

// Takes tail of list. Deletes all elements that follow
void deleteDLList(Node *DLList);

// Takes start node. Returns the length of list
size_t getDLListLen(Node *Dll);

// Reuturns uncast pointer to value at index or NULL on fail
void *getValueByIndex(Node *Dll, size_t index);

// create new node at tail of doubly lined list
int addToTail(Node **tail, void *value, size_t valueSize);

// create new node at head of doubly lined list
int addToHead(Node **head, void *value, size_t valueSize);

// Inser value at index. Returns 0 on successful insertion. -1 if fails
int insertValueAtIndex(Node **Dll, size_t index, void *newValue, size_t valueSize);

// Set value at node by reference to node
int setValueByNode(Node *node, void *newValue, size_t valueSize);

// Set value at doubly linked list by index from tail;
int setValueByIndex(Node *head, void *newValue, size_t valueSize, size_t index);

// Deletes value at index. May move tail and head
int deleteNodeByIndex(Node **tail, Node **head, int index);

// Delete node in doubly linked list by node reference
int deleteNodeByRef(Node **head, Node **tail, Node *node);

// Prints the linked list from tail to head
void printLinkedListFromTail(Node *tail, void (*printFunction)(void *value));

// Function for printLinkedListFromTail(). Prints ints
void printInt(void *value);

#endif