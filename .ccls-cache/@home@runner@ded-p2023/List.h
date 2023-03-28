typedef void* Type;
typedef struct strList* List;
typedef enum {FALSE, TRUE} Bool;

List list_create(void (*destructor)(void*));
void list_destroy(List);
int list_size(List);
void list_add(List, Type);
Type list_get(List, int);
void list_set(List, Type, int);
Type list_remove(List, int);
