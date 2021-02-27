class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None;

def create_linked_list(data):
    linked_list = LinkedList()
    for elem in data:
        last_elem = get_last_elem(linked_list)
        new_node = Node(elem)
        # linked list is empty
        if last_elem == None:
            linked_list.head = new_node    
        # linked list is not empty
        else:
            last_elem.next = new_node
    return linked_list
        
def get_last_elem(linked_list):
    curr = linked_list.head
    prev = None
    while curr != None:
        prev = curr
        curr = curr.next
    return prev    

def print_linked_list(linked_list):
    curr = linked_list.head
    i = 0
    while curr != None:
        print(f"Element {i} has data {curr.data} at address {hex(id(curr))}")
        i += 1
        curr = curr.next

linked_list = create_linked_list([1,2,3])
print_linked_list(linked_list)
