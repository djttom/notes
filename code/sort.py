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
                                                                                
                                                                                
def test_merge_sort():                                                          
    s = [38, 27, 43, 3, 9, 82, 10]                                              
    print("before sort:", s)                                                    
    merge_sort(s)                                                               
    print(" after sort:", s)                                                    
                                                                                
if __name__ == '__main__':                                                      
    test_merge_sort()
