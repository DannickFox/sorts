/**
 * main.c
 * Sorting algorithms. Just for fun.
 * Compile with: gcc -o sorting main.c sorts.c
 * 
 * Run in console. With no arguments the program will generate a default array
 * and use the default set function for sorting. Test other sorts by adding the
 * array size as first argument and the name of the sort to use as the second.
 * Available options are: bubble, insertion, selection, quick, quickLR, merge,
 * heap and bogo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorts.h"

// Default input quantity.
#define d_N 10
// Default input sort option.
#define d_S 5
// Number of available sorts.
#define N_sorts 8

unsigned long checksum(int *ar, size_t N);
void printArray(int *, size_t);

int main(int argc, char *argv[])
{

    void (*sorts[N_sorts])(int *, size_t) = { // Available sorting algorithms to test.
        sort_bubble, sort_insert, sort_select, sort_quick, sort_quickLR, sort_merge, sort_heap, sort_bogo
    };
    char *sortNames[N_sorts] = { // Names for user selection.
        "bubble", "insertion", "selection", "quick", "quickLR", "merge", "heap", "bogo"
    };
    int sortOp = d_S; // Option set to default.

    // Initialize random number generator.
    srand(time(NULL));

    // User-selected quantity. Defaults to d_N at invalid input.
    size_t N;
    if (argc > 1)
    {
        int x = atoi(argv[1]);
        N = x > 0 ? x : d_N;
        if (argc > 2) 
        {
            int i;
            for (i = 0; i < N_sorts; i++)
            {
                if(strcmp(sortNames[i], argv[2]) == 0) break;                
            }

            if (i < N_sorts)
            {
                sortOp = i;
            } 
        }
    }
    else
    {
        N = d_N;
    }

    if (N > 1000) printf("Generating array...\n");
    int *ar = malloc(N * sizeof(int)); // Reserve memory for array.

    if (ar)
    {
        for(int i = 0; i < N; i++) ar[i] = i; // Fill array.
        randomize(ar, N); // Shuffle array.

        void (*sfunc)(int*, size_t) = sorts[sortOp]; // Selected sort to use.

        unsigned long chk_unsorted = checksum(ar, N); // First checksum to check integrity later.
        printf("Total elements: %i\n", N);
        printf("Method used: %s\n", sortNames[sortOp]);

        if(N > 100)
        {
            puts("Array is too large to display properly.");
            puts("Sorting...");
            clock_t t_count = clock(); // Time is measured in the case of very large arrays.
            sfunc(ar, N);
            t_count = clock() - t_count;
            puts("Done.");
            if (t_count > 0) printf("Array sorted in %.3lf seconds.\n",(double) t_count / CLOCKS_PER_SEC);
        } else
        {
            // Show unsorted array.
            printf("Unsorted:\n");
            printArray(ar, N);

            sfunc(ar, N);

            // Show sorted array.
            printf("Sorted:\n");
            printArray(ar, N);
        }

        // Verification of sorting function.
        unsigned long chk_sorted = checksum(ar, N);
        if((chk_sorted == chk_unsorted) && isSorted(ar, N))
        {
            puts("Array was sorted correctly.");
        } else {
            puts("Function may have not sorted elements correctly.");
        }

        free(ar);
    }
    else
    {
        perror("Could not generate array");
    }

    return 0;
}

// Sums every integer in array to check integrity.
unsigned long checksum(int *ar, size_t N)
{
    unsigned long x = 0;

    for (int i = 0; i < N; i++)
    {
        x += ar[i];
    }

    return x;
}

// Prints array in [a0, a1, ..., aN-1] format.
void printArray(int *ar, size_t N)
{
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf("%i%s", ar[i], i == N - 1 ? "]\n" : ", ");
    }
}
