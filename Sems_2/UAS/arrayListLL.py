# Array
array = [1, 2, 3, 4, 5]
print("Array: ", array)

# Array List
class Arraykai:
    def __init__(self):
        self.items = []

    def tianjia(self, value):
        self.items.append(value)

    def get(self, index):
        return self.items[index]

array_kai = Arraykai()
array_kai.tianjia(1)
array_kai.tianjia(2)
array_kai.tianjia(3)
print("Array List: ", array_kai.items)

# Singly Linked List
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class SinglyLinkedkai:
    def __init__(self):
        self.head = None

    def tianjia(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            sekarang = self.head
            while sekarang.next:
                sekarang = sekarang.next
            sekarang.next = Node(data)

    def print_kai(self):
        node = self.head
        while node is not None:
            print(node.data, end=" ")
            node = node.next
        print()

singly_linked_kai = SinglyLinkedkai()
singly_linked_kai.tianjia(1)
singly_linked_kai.tianjia(2)
singly_linked_kai.tianjia(3)
print("Singly Linked List: ", end="")
singly_linked_kai.print_kai()

# Doubly Linked List
class DNode:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedkai:
    def __init__(self):
        self.head = None

    def tianjia(self, data):
        if not self.head:
            self.head = DNode(data)
        else:
            sekarang = self.head
            while sekarang.next:
                sekarang = sekarang.next
            new_node = DNode(data)
            sekarang.next = new_node
            new_node.prev = sekarang

    def print_kai(self):
        node = self.head
        while node is not None:
            print(node.data, end=" ")
            node = node.next
        print()

doubly_linked_kai = DoublyLinkedkai()
doubly_linked_kai.tianjia(1)
doubly_linked_kai.tianjia(2)
doubly_linked_kai.tianjia(3)
print("Doubly Linked List: ", end="")
doubly_linked_kai.print_kai()
print("\n Lead Them To Paradise! - Abdulhadi")