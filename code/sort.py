''' sort functions '''

def merge_sort(s):                                                              
    ''' divide and conquer                                                      
        divide into two sub-sequence, compare and merge back recursively        
    '''                                                                         
    if len(s) > 1:                                                              
        # first divide into two sub-sequence                                    
        m = len(s) // 2                                                         
        sl = s[:m]                                                              
        sr = s[m:]                                                              
                                                                                
        # recursive merge sort each sub-sequence                                
        merge_sort(sl)                                                          
        merge_sort(sr)                                                          
                                                                                
        # compare between two sub-sequence and merge back                       
        i = j = k = 0                                                           
        while i < len(sl) and j < len(sr):                                      
            if sl[i] < sr[j]:                                                   
                s[k] = sl[i]                                                    
                i += 1                                                          
            else:                                                               
                s[k] = sr[j]                                                    
                j += 1                                                          
            k += 1                                                              
                                                                                
        while i < len(sl):                                                      
            s[k] = sl[i]                                                        
            k += 1; i += 1                                                      
        while j < len(sr):                                                      
            s[k] = sr[j]                                                        
            k += 1; j += 1                                                      
                                                                                
                                                                                
def partition(s, l, r):
    pivot = s[r]
    i = l - 1

    for j in range(l, r):
        if s[j] < pivot:
            i += 1
            s[i], s[j] = s[j], s[i]
    # swap pivot with the first greater item at i+1
    s[i + 1], s[r] = s[r], s[i + 1]
    return i + 1

def quick_sort(s, l, r):
    if l < r:
        pi = partition(s, l, r)
        quick_sort(s, l, pi - 1)
        quick_sort(s, pi + 1, r)

                                                                                
if __name__ == '__main__':                                                      
    s0 = [38, 27, 43, 3, 9, 82, 10]                                              

    print("test merge sort")
    s = s0[:]
    print("before sort:", s)                                                    
    merge_sort(s)                                                               
    print(" after sort:", s)                                                    

    print("test quick sort")
    s = s0[:]
    print("before sort:", s)                                                    
    quick_sort(s, 0, len(s) - 1)
    print(" after sort:", s)                                                    
