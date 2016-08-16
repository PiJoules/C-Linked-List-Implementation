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

static int str_equal(const char* str1, const char* str2){
    return !strcmp(str1, str2);
}

int main(int argc, char* argv[]){
    LinkedList* ll = ll_create(free, SIMPLE_VOID(str_copy), str_equal);

    assert(ll->size == 0);
    assert(ll->head == NULL);

    ll_prepend(ll, "val1");
    ll_prepend(ll, "val2");
    ll_prepend(ll, "val3");
    assert(ll->size == 3);
    assert(!strcmp(ll_get(ll, 0), "val3"));
    assert(!strcmp(ll_get(ll, 2), "val1"));
    assert(ll_get(ll, 10) == NULL);

    char* str = ll_str(ll);
    printf("%s\n", str);
    free(str);

    LinkedList* copied_ll = ll_copy(ll);
    assert(ll_equal(copied_ll, ll));
    str = ll_str(copied_ll);
    printf("%s\n", str);
    free(str);

    ll_remove(ll, 0);
    ll_remove(ll, 1);
    ll_remove(ll, 10);
    assert(ll->size == 1);
    assert(!strcmp(ll_get(ll, 0), "val2"));

    assert(!ll_equal(copied_ll, ll));

    str = ll_str(ll);
    printf("%s\n", str);
    free(str);
    str = ll_str(copied_ll);
    printf("%s\n", str);
    free(str);
    

    ll_free(ll);
    ll_free(copied_ll);

    return 0;
}
