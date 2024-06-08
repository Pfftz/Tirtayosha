# Array
array = [1, 2, 3, 4, 5]
print("Array: ", array)

# Array List
class ArrayList:
    def __init__(self):
        self.items = []

    def add(self, value):
        self.items.append(value)

    def get(self, index):
        return self.items[index]

array_list = ArrayList()
array_list.add(1)
array_list.add(2)
array_list.add(3)
print("Array List: ", array_list.items)

# Singly Linked List
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def add(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)

    def print_list(self):
        node = self.head
        while node is not None:
            print(node.data, end=" ")
            node = node.next
        print()

singly_linked_list = SinglyLinkedList()
singly_linked_list.add(1)
singly_linked_list.add(2)
singly_linked_list.add(3)
print("Singly Linked List: ", end="")
singly_linked_list.print_list()

# Doubly Linked List
class DNode:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def add(self, data):
        if not self.head:
            self.head = DNode(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            new_node = DNode(data)
            current.next = new_node
            new_node.prev = current

    def print_list(self):
        node = self.head
        while node is not None:
            print(node.data, end=" ")
            node = node.next
        print()

doubly_linked_list = DoublyLinkedList()
doubly_linked_list.add(1)
doubly_linked_list.add(2)
doubly_linked_list.add(3)
print("Doubly Linked List: ", end="")
doubly_linked_list.print_list()
print("\n Lead Them To Paradise! - Abdulhadi")