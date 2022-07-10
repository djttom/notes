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
