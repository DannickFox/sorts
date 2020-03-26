// sorts.c

#include <stdlib.h>
#include "sorts.h"

int isSorted(int *ar, size_t N)
{
    int sorted = 1, i = 0;
    
    while (sorted && i < N - 1) 
    {
        if(ar[i] > ar[i + 1])
        {
            sorted = 0;
        }
        i++;
    }

    return sorted;
}


// Swaps contents of two integer pointers.
void swp(int *a, int *b)
{
    int x;
    x = *a;
    *a = *b;
    *b = x;
}

void randomize(int *ar, size_t N)
{
    for(int i = 0; i < N; i++)
    {
        int r = rand() % N;
        swp(ar + i, ar + r);
    }
}

void sort_bubble(int *ar, size_t N)
{
    int sorted = 0;

    while(!sorted)
    {
        sorted = 1;
        for(int i = 0; i < N - 1; i++)
        {   
            if(ar[i] > ar[i + 1])
            {
                sorted = 0;
                swp(ar + i, ar + i + 1);
            }
        }
        N--;
    }    
}

void sort_insert(int *ar, size_t N)
{
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if (ar[j + 1] < ar[j])
            {
                swp(ar + j + 1, ar + j);
            } else
            {
                break;
            }
        }
    }
}

void sort_select(int *ar, size_t N)
{
    for(int i = 0; i < N; i++)
    {
        int *x = ar + i;

        // Find smallest element.
        for(int j = i; j < N; j++)
        {
            if(ar[j] < *x)
            {
                x = ar + j;
            }
        }
        swp(x, ar + i);
    }
}

void sort_quick(int *ar, size_t N)
{
    // Partition array according to pivot.
    if (N > 1)
    {

        int *p  = ar + N - 1; // Select pivot.
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            if (ar[i] < *p)
            {
                swp(ar + i, ar + j++);
            }
        }
        swp(ar + j, p);
        p = ar + j;

        sort_quick(ar, p - ar); // Left side.
        sort_quick(p + 1, (ar + N - 1) - p); // Right side.
    }
}

void sort_quickLR(int *ar, size_t N)
{
    if (N > 1)
    {
        int *L = ar, *R = ar + N - 1;
        int f = 0;

        while (L != R)
        {
            if(*L > *R)
            {
                swp(L, R);
                f = f == 0 ? 1 : 0;
            }

            // Shifts pointers according to last swap.
            if (f == 0) R = R - 1;
            else L = L + 1;
        }

        // Recursive divide & conquer. Array divided by resulting pivot.
        sort_quickLR(ar, L - ar + 1); // Left side.
        sort_quickLR(L + 1, (ar + N - 1) - L); // Right side.
    }
}

void sort_merge(int *ar, size_t N)
{
    if(N > 1)
    {
        // Set boundaries to split array.
        int N2 = N / 2; // Right quantity.
        int N1 = N - N2; // Left quantity.
        int *ar2 = ar + N1; // Start of right side.

        // Recursive divide & conquer.
        sort_merge(ar, N1); // Left side.
        sort_merge(ar2, N2); // Right side.

        // Secondary memory space for merging.
        int *x = malloc(N * sizeof(int)); // Reserved after recursion to save space.
        if (x)
        {
            int j = 0, k = 0;

            // Merging loop.
            for (int i = 0; i < N; i++)
            {
                if (j < N1 && k < N2) // Pick and place lower value.
                {
                    if (ar[j] < ar2[k])
                    {
                        x[i] = ar[j++];
                    } else
                    {
                        x[i] = ar2[k++];
                    }
                } else if (j < N1) // Place remaining elements. Left side.
                {
                    x[i] = ar[j++];
                } else if (k < N2) // Place remaining elements. Right side.
                {
                    x[i] = ar2[k++];
                }
            }
            
            // Copy merged to main array.
            for(int i = 0; i < N; i++)
            {
                ar[i] = x[i];
            }

            free(x);
        }
    }
}

void sort_bogo(int *ar, size_t N)
{
    int tries = 0; // Counter to avoid infinite loop.
    while(!isSorted(ar, N) && ++tries < 1000)
    {
        randomize(ar, N);
    }
}
