# C Linked List Implementation

Include "linked_list.h" to use functions.

Example usage in "test_linked_list.c".

## Building
```sh
$ make
$ make test
```

## Avaialble functions
```c
LinkedList* ll_create();
void ll_free(LinkedList*);
void ll_prepend(LinkedList* ll, void* elem);
void* ll_get(LinkedList* ll, size_t idx);
void ll_remove(LinkedList* ll, size_t idx);
```
