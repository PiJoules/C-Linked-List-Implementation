# C Linked List Implementation

Include "linked_list.h" to use functions.

Example usage in "test_linked_list.c".

## Building
```sh
$ make
$ make test
```

## Avaialble functions/data structures
```c
struct LinkedListNode {
    void* value;
    LinkedListNode* next;
};

struct LinkedList {
    size_t size;
    void (*free_func)(void*);
    void* (*copy_func)(void*);
    int (*eq_func)(void*, void*);
    LinkedListNode* head;
};

LinkedList* ll_create(void (*free_func)(void*), void* (*copy_func)(void*), int (*eq_func)(void*, void*));
void ll_free(LinkedList*);
void ll_prepend(LinkedList* ll, void* elem);
void* ll_get(LinkedList* ll, size_t idx);
void ll_remove(LinkedList* ll, size_t idx);
LinkedList* ll_copy(LinkedList* ll);
int ll_equal(LinkedList* ll, LinkedList* other);
char* ll_str(LinkedList* ll);
void ll_remove_value(LinkedList* ll, void* value);
```
