#from array import *
# Recursive Linear Search 

def linear_search_best(arr, size, key_b):
  
    if size == 0:
        return -1
    elif arr[size - 1] == key_b:
        return size - 1
    else:
        ans = linear_search_best(arr, size - 1, key_b)
        return ans 
    

def linear_search_worse(arr, size, key_w):
    if size == 0:
        return -1
    elif arr[size - 1] == key_w:
        return size - 1
    else:
        ans_w = linear_search_worse(arr, size - 1, key_w)
        return ans_w


arr = [3, 55, 12, 5, 7, 23, 34, 11, 17, 42, 1, 14]
key_w = 14
key_b = 3

ans = linear_search_best(arr, len(arr), key_b)

if ans == - 1:
    print( "The element ", key_b, " is not found.")
else: 
    print( "The best case element " , key_b, " is found at ",ans," index of the given array.")

ans_w = linear_search_worse(arr, len(arr), key_w)

if ans_w == - 1:
    print( "The element ", key_w, "is not found.")
else:
    print( "The worst case element ", key_w, " is found at ", ans_w," index of the given array.")

    #find_linear_search(arr, size, key_b)

