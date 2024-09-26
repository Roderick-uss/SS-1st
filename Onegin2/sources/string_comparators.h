#ifndef  STRING_SORTS
#define  STRING_SORTS

//typedef int (*cmp_t)(const void*, const void*);

int compare_strings_front(const void* a, const void* b);
int compare_strings_back (const void* a, const void* b);

int my_num_cmp(const void* a, const void* b);

//void bubble_sort(void* text, size_t size, size_t el_size, cmp_t cmp);

#endif// STRING_SORTS
