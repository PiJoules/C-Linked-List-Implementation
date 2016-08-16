#include <assert.h>
#include "linked_list.h"

#define SIMPLE_VOID(var) (void* (*)(void*))var

/**
 * Custom strdup function for testing.
 */
static char* str_copy(const char* str){
    size_t len = strlen(str);
    char* new_str = (char*)malloc(sizeof(char) * len + 1);
    if (!new_str){
        perror("malloc failed");
        return NULL;
    }
    strncpy(new_str, str, len);
    new_str[len] = '\0';
    return new_str;
}

int main(int argc, char* argv[]){
    LinkedList* ll = ll_create(free, SIMPLE_VOID(str_copy));

    assert(ll->size == 0);
    assert(ll->head == NULL);

    ll_prepend(ll, "val1");
    ll_prepend(ll, "val2");
    ll_prepend(ll, "val3");
    assert(ll->size == 3);
    assert(!strcmp(ll_get(ll, 0), "val3"));
    assert(!strcmp(ll_get(ll, 2), "val1"));
    assert(ll_get(ll, 10) == NULL);

    ll_remove(ll, 0);
    ll_remove(ll, 1);
    ll_remove(ll, 10);
    assert(ll->size == 1);
    assert(!strcmp(ll_get(ll, 0), "val2"));

    ll_free(ll);

    return 0;
}
