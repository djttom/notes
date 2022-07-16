#include <stdio.h>                                                              
#include <string.h>                                                             

/* merge sort
 *
 * muick sort is a divide-and-conquer algorithm. The sequence is divided into
 * two equal halves and then combined is a sorted manner.
 * - Divide the n-element sequence into two sub-sequence of n/2 elements each.
 * - Conquer recursively sort the two sub-sequences
 * - Combine and merge the two sorted sub-sequences to produce the sorted answer.
 *
 * Time Complexity: T(n) = 2T(n/2) + D(n) + C(n) = O(nlgn)
 * - D(n) and C(n) are the divide and combine time
 * - worse case is O(n**2), T(n) = T(0) + T(n-1) + P(n) = T(n-1) + P(n)
 *   best or average case is O(nlgn) = T(n) = T(n/2) + P(n)
 *
 * Merge sort is not in-place sorting. It needs extra O(n) space temporarily to
 * store items in merge. It's good for linked-list sort since insert item
 * needs O(1) space and O(1) time.
 *
 * merge_sort(s[],l,r):
 *     if l < r:
 *         m = (l + r) / 2
 *         merge_sort(s, l, m)
 *         merge_sort(s, m+1, r)
 *         merge(s, l, m, r)
 */
                                                                                
/*                                                                              
 * compare items from two sub-sequence and merge into sequence in sorted.       
 */                                                                             
int merge(int s[], int l, int m, int r)                                         
{                                                                               
    int i, j, k;                                                                
    int nl = m - l + 1;                                                         
    int nr = r - m;                                                             
                                                                                
    int sl[nl], sr[nr];                                                         
                                                                                
    // save the two sub-sequence                                                
    for (i = 0; i < nl; i++)                                                    
        sl[i] = s[l + i];                                                       
    for (i = 0; i < nr; i++)                                                    
        sr[i] = s[m + 1 + i];                                                   
                                                                                
    // compare between the two sub-sequence and merge back                      
    i = 0; j = 0; k = l;                                                        
    while (i < nl && j < nr) {                                                  
        if (sl[i] < sr[j]) {                                                    
            s[k] = sl[i];                                                       
            i++;                                                                
        } else {                                                                
            s[k] = sr[j];                                                       
            j++;                                                                
        }                                                                       
        k++;                                                                    
    }                                                                           
    for (;i < nl; i++, k++) {                                                   
        s[k] = sl[i];                                                           
    }                                                                           
    for (;j < nr; j++, k++) {                                                   
        s[k] = sr[j];                                                           
    }                                                                           
                                                                                
    return (0);                                                                 
}

/*
 * divide and conquer merge sort.
 */
int merge_sort(int s[], int l, int r)
{
    int m;
    static int n = 0;

    n++;
    //printf("%s(): count %d, %d items\n", __func__, n, r - l + 1);
    if (l < r) {
        // divide into two sub-sequence and merge sort each sub-sequence
        m = l + (r - l) / 2;
        merge_sort(s, l, m);
        merge_sort(s, m + 1, r);

        // compare and merge two sub-sequence into sequence in sorted
        merge(s, l, m, r);
    }

    return 0;
}

void test_merge_sort()
{
    int i;
    int S0[] = {38, 27, 43, 3, 9, 82, 10};
    int n0 = sizeof (S0) / 4;

    printf("test merge sort\n");
    printf("before sort: ");
    for (i = 0; i < n0; i++) {
        printf("%2d ", S0[i]);
    }
    printf("\n");
    printf(" after sort: ");
    merge_sort(S0, 0, n0 - 1);
    for (i = 0; i < n0; i++) {
        printf("%2d ", S0[i]);
    }
    printf("\n");
}

/*
 * quick sort
 *
 * quick sort is a divide-and-conquer algorithm. It picks an element as a pivot
 * and partitions the given array around the pivot.
 * - Divide the n-element sequence into two non-empty subsequence such that
 * all elements in S[p..q] are less than or equal to all elements in S[q+1..r]
 * the pivot index q is compulted as part of the partioning procedure.
 * - Conquer recursively sort the two sub-sequences
 * - Combine the two sub-quences to produce the sorted answer with no work needed
 * since the subsequences are sorted in place already.
 *
 * Time Complexity: T(n) = T(k) + T(n-k-1) + P(n)
 * - k is the number of elements that are smaller than the pivot
 * - P(n) is the partion time
 * - worse case is O(n**2), T(n) = T(0) + T(n-1) + P(n) = T(n-1) + P(n)
 *   best or average case is O(nlgn) = T(n) = T(n/2) + P(n)
 *
 * Quick sort is in-space sorting while merge sort requires extra storage.
 * Merge sort is prefered over quick sort for linked lists because the insert
 * in the middle in O(1) space and O(1) time.
 *
 * Pseduo-code
 * quick_sort(s[],l,r):
 *     if l < r:
 *         p = partition(s, l, r)
 *         quick_sort(s, l, p)
 *         quick_sort(s, p+1, r)
 *
 */

void swap (int *a, int *b)
{
    int t = *a;
    *a = *b; *b = t;
}

/*
 * pick the last element as pivot, compare and place the pivot element at 
 * its correct position in sorted array, place all smaller itemss than pivot
 * to the left of pivot, and all greater items to the right.
 */
int partition (int s[], int low, int high)
{
    int i, j;
    int pivot;

    // pick last element as pivot
    pivot = s[high];

    i = low - 1;
    for (j = low; j < high; j++) {
        if (s[j] < pivot) {
            // i always points to the last processed item that is smaller than
            // pivot, and item i+1 could be greater than pivot.
            //
            // when item j is smaller than pivot, swap it with the
            // item at i+1 which is larger than pivot, because i always 
            // point to last item that is processed and smaller than pivot.
            i++;
            swap(&s[i], &s[j]);
        }
    }
    // swap pivot and item i+1 (point to first item larger than pivot),
    // now i+1 is the pivot position after swap
    swap(&s[i + 1], &s[high]);
    return (i + 1);
}

int quick_sort (int s[], int low, int high)
{
    int pi;

    if (low < high) {
        // pivot index
        pi = partition(s, low, high);
        //printf("%s(): count %d items from %d-%d, pivot s[%d] %d\n", __func__, high-low+1, low, high, pi, s[pi]);

        // sort each sub-sequence around the pivot
        quick_sort(s, low, pi - 1);
        quick_sort(s, pi + 1, high);
    }

    return 0;
}


void test_sort()
{
    int i;
    int s0[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof (s0) / 4;
    int s[n];

    printf("test merge sort\n");
    memcpy(s, s0, sizeof s0);
    printf("before: ");
    for (i = 0; i < n; i++) {
        printf("%2d ", s0[i]);
    }
    printf("\n");
    merge_sort(s, 0, n - 1);
    printf(" after: ");
    for (i = 0; i < n; i++) {
        printf("%2d ", s[i]);
    }
    printf("\n");

    printf("test quick sort\n");
    memcpy(s, s0, sizeof s0);
    printf("before: ");
    for (i = 0; i < n; i++) {
        printf("%2d ", s0[i]);
    }
    printf("\n");
    quick_sort(s, 0, n - 1);
    printf(" after: ");
    for (i = 0; i < n; i++) {
        printf("%2d ", s[i]);
    }
    printf("\n");
}

int main(void)
{
    printf("%s\n", __FILE__);

    //test_merge_sort();
    //test_quick_sort();
    test_sort();

    return 0;
}
