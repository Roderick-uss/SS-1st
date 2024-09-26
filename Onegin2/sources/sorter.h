#ifndef  SORTER
#define  SORTER

typedef int (*cmp_t)(const void*, const void*);

void bubble_sort(void* base, size_t size, size_t el_size, cmp_t cmp);
void quic_sort  (void* base, size_t size, size_t el_size, cmp_t cmp);

#endif// SORTER
