def linear_search(arr, target):
    # loop through each element in the array
    for i in range(len(arr)):
        # if the current element is equal to the target, return its index
        if arr[i] == target:
            return i            
    # if the target is not found in the array, return -1
    return -1

arr = [21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
target = 24
result = linear_search(arr, target)
print(f"The index of {target} is {result}.")  