# Array
array = [1, 2, 3, 4, 5]
print("Array: ", array)

class Arraykai:
    def __init__(self):
        self.units = []

    def tianjia(self, value):
        self.units.append(value)

    def get(self, index):
        return self.units[index]

array_kai = Arraykai()
array_kai.tianjia(1)
array_kai.tianjia(2)
array_kai.tianjia(3)
print("Array List: ", array_kai.units)

# Singly Linked List
class singlyNode:
    def __init__(self, data=None):
        self.data = data
        self.selanjutnya = None

class SinglyLinkedkai:
    def __init__(self):
        self.kepala = None

    def tianjia(self, data):
        if not self.kepala:
            self.kepala = singlyNode(data)
        else:
            sekarang = self.kepala
            while sekarang.selanjutnya:
                sekarang = sekarang.selanjutnya
            sekarang.selanjutnya = singlyNode(data)

    def print_kai(self):
        node = self.kepala
        while node is not None:
            print(node.data, end=" ")
            node = node.selanjutnya
        print()

singly_linked_kai = SinglyLinkedkai()
singly_linked_kai.tianjia(1)
singly_linked_kai.tianjia(2)
singly_linked_kai.tianjia(3)
print("Singly Linked List: ", end="")
singly_linked_kai.print_kai()

class DNode:
    def __init__(self, data=None):
        self.data = data
        self.selanjutnya = None
        self.sebelumnya = None

class DoublyLinkedkai:
    def __init__(self):
        self.kepala = None

    def tianjia(self, data):
        if not self.kepala:
            self.kepala = DNode(data)
        else:
            sekarang = self.kepala
            while sekarang.selanjutnya:
                sekarang = sekarang.selanjutnya
            new_node = DNode(data)
            sekarang.selanjutnya = new_node
            new_node.sebelumnya = sekarang

    def print_kai(self):
        node = self.kepala
        while node is not None:
            print(node.data, end=" ")
            node = node.selanjutnya
        print()

doubly_linked_kai = DoublyLinkedkai()
doubly_linked_kai.tianjia(1)
doubly_linked_kai.tianjia(2)
doubly_linked_kai.tianjia(3)
print("Doubly Linked List: ", end="")
doubly_linked_kai.print_kai()
print("\n Lead Them To Paradise! - Abdulhadi")