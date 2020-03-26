<<<<<<< HEAD
// sorts.h
// Sorting algorithm library.

#include <stdlib.h>

#ifndef SORTS_H
#define SORTS_H

// Check if values are in order.
int isSorted(int *ar, size_t N);

// Randomize an array.
void randomize(int *ar, size_t N);

// Bubble sort algorithm.
void sort_bubble(int *ar, size_t N);

// Insertion sort algorithm.
void sort_insert(int *ar, size_t N);

// Selection sort algorithm.
void sort_select(int *ar, size_t N);

// Quick sort algorithm.
void sort_quick(int *ar, size_t N);

// Quick sort algorithm. Using LR pointers.
void sort_quickLR(int *ar, size_t N);

// Merge sort algorithm.
void sort_merge(int *ar, size_t N);

// Bogo sort algorithm. Only gets 1000 tries before giving up.
void sort_bogo(int *ar, size_t N);

=======
// sorts.h
// Sorting algorithm library.

#include <stdlib.h>

#ifndef SORTS_H
#define SORTS_H

// Check if values are in order.
int isSorted(int *ar, size_t N);

// Randomize an array.
void randomize(int *ar, size_t N);

// Bubble sort algorithm.
void sort_bubble(int *ar, size_t N);

// Insertion sort algorithm.
void sort_insert(int *ar, size_t N);

// Selection sort algorithm.
void sort_select(int *ar, size_t N);

// Quick sort algorithm.
void sort_quick(int *ar, size_t N);

// Quick sort algorithm. Using LR pointers.
void sort_quickLR(int *ar, size_t N);

// Merge sort algorithm.
void sort_merge(int *ar, size_t N);

// Bogo sort algorithm. Only gets 1000 tries before giving up.
void sort_bogo(int *ar, size_t N);

>>>>>>> 4515a960c9fd7cc7f856899eeac9deafd0d77dce
#endif