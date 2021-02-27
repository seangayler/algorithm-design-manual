# Going to print same memory address of each element in array

ARRAY_SIZE = 10
array = [0] * ARRAY_SIZE

def print_array(array):
    for i in range(len(array)):
        print(f"Element {i} has memory address {hex(id(array[i]))}.")

print_array(array)
