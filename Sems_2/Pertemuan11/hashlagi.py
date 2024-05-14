'''vault 101 employee database using hash table'''
import os

# Node class
class Node:
    def __init__(self, key, val, next=None):
        self.key = key
        self.val = val
        self.next = next

# HashTable class
class HashTable:
    def __init__(self, size):
        self.size = size
        self.count = 0
        self.table = [None for _ in range(self.size)]

    def _hash(self, key):
        return hash(key) % self.size

    def _load_factor(self):
        return self.count / self.size

    def _resize(self):
        if self._load_factor() > 0.9:
            self.size *= 2
            new_table = [None for _ in range(self.size)]
            for i in range(len(self.table)):
                node = self.table[i]
                while node is not None:
                    hash_key = self._hash(node.key)
                    new_table[hash_key] = Node(
                        node.key, node.val, new_table[hash_key])
                    node = node.next
            self.table = new_table

    def insert(self, key, name, job, age, sex, eyes, hair, status):
        employee = {"name": name, "job": job, "age": age,
                    "sex": sex, "eyes": eyes, "hair": hair, "status": status}
        hash_key = self._hash(key)
        node = self.table[hash_key]
        while node is not None:
            if node.key == key:
                node.val = employee
                return
            node = node.next
        self.table[hash_key] = Node(key, employee, self.table[hash_key])
        self.count += 1
        if self._load_factor() > 0.9:
            self._resize()

    def find(self, key):
        hash_key = self._hash(key)
        node = self.table[hash_key]
        while node is not None:
            if node.key == key:
                return node.val
            node = node.next
        return None

    def delete(self, key):
        hash_key = self._hash(key)
        node = self.table[hash_key]
        if node is None:
            return None
        if node.key == key:
            self.table[hash_key] = node.next
            return
        while node.next is not None:
            if node.next.key == key:
                node.next = node.next.next
                return
            node = node.next


def main():
    vault = HashTable(101)
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')  # Clear the terminal
        print("\nROBCO INDUSTRIES UNIFIED OPERATING SYSTEM")
        print("  COPYRIGHT 2075-2077 ROBCO INDUSTRIES")
        print("              -Server 10-")
        print("\n-Vault 101 Employee Database-")
        print("\nWelcome, Overseer")
        print("=================================")
        print("\n 1. Insert\n 2. Find\n 3. Delete\n 4. Quit")
        option = input(" Please Choose an option: ")
        try:
            if option == '1':
                key = int(input("\n Enter an ID: "))
                name = input(" Enter a name: ")
                job = input(" Enter a job: ")
                age = int(input(" Enter an age: "))
                sex = input(" Enter a sex: ")
                eyes = input(" Enter an eye color: ")
                hair = input(" Enter a hair color: ")
                status = input(" Enter a status (alive/dead): ")
                vault.insert(key, name, job, age, sex, eyes, hair, status)
            elif option == '2':
                key = int(input(" Enter a ID: "))
                result = vault.find(key)
                if result is not None:
                    print(" Found: ", result)
                else:
                    print(" ID not found.")
            elif option == '3':
                key = int(input(" Enter a ID: "))
                vault.delete(key)
                print(" ID deleted.")
            elif option == '4':
                print("\n Thank you for using Vault 101 Employee Database\n\n Goodbye, Overseer\n")
                break
            else:
                print(" Invalid option, please try again.")
            # Wait for the user to press Enter before clearing the terminal
            print("\n=================================")
            input("\nPress Enter to continue...")
        except ValueError:
            print(" Invalid input, please try again.")
            input("\nPress Enter to continue...")


if __name__ == "__main__":
    main()
