#include <stdio.h>                                                              
#include <string.h>                                                             
                                                                                
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

int main(void)
{
    printf("%s\n", __FILE__);

    test_merge_sort();

    return 0;
}
