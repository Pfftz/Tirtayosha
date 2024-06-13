'''Overseer: Abdulhadi Muntashir'''
import os

# Node class
class sigmaNode:
    def __init__(self, key, val, next_node=None):
        self.key = key
        self.val = val
        self.next = next_node

# HashTable class
class tableHashing:
    def __init__(self, size):
        self.size = size
        self.count = 0
        self.tabel = [None for _ in range(self.size)]

    def _hush(self, key):
        return hash(key) % self.size

    def _load_factor(self):
        return self.count / self.size

    def _resize(self):
        if self._load_factor() > 0.75:
            self.size *= 2
            new_tabel = [None for _ in range(self.size)]
            for node in self.tabel:
                while node is not None:
                    hush_key = self._hush(node.key)
                    new_tabel[hush_key] = sigmaNode(
                        node.key, node.val, new_tabel[hush_key])
                    node = node.next
            self.tabel = new_tabel

    def insert(self, key, name, job, age):
        # Membuat dictionary untuk karyawan
        karyawan = {"name": name, "job": job, "age": age}
        hush_key = self._hush(key)
        node = self.tabel[hush_key]

        # Mencari node dengan kunci yang sama dan mengganti nilainya
        while node is not None:
            if node.key == key:
                node.val = karyawan
                return
            node = node.next

        # Menambahkan node baru jika tidak ada node dengan kunci yang sama
        self.tabel[hush_key] = sigmaNode(key, karyawan, self.tabel[hush_key])
        self.count += 1

        # Mengubah ukuran tabel jika faktor beban lebih dari 0.75
        if self._load_factor() > 0.75:
            self._resize()

    def find(self, key):
        hush_key = self._hush(key)
        node = self.tabel[hush_key]
    
        # Mencari node dengan kunci yang diberikan
        while node is not None:
            if node.key == key:
                return node.val
            node = node.next
    
        # Mengembalikan None jika tidak ada node dengan kunci yang diberikan
        return None
    
    def delete(self, key):
        hush_key = self._hush(key)
        node = self.tabel[hush_key]
    
        # Menghapus node jika kunci cocok
        if node and node.key == key:
            self.tabel[hush_key] = node.next
            return
    
        # Mencari node berikutnya jika kunci tidak cocok
        while node and node.next:
            if node.next.key == key:
                node.next = node.next.next
                return
            node = node.next


def main():
    vault = tableHashing(111)
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')  # Clear the terminal
        print("\nWelcome to ROBCO Industries (TM) Termlink\n")
        print("  COPYRIGHT 2075-2077 ROBCO INDUSTRIES")
        print("              -Server 10-")
        print("\n-Vault 111 Employee Database-")
        print("\nWelcome, Abdulhadi Muntashir")
        print("=================================")
        print("\n 1. Insert\n 2. Find\n 3. Delete\n 4. Output All\n 5. Quit")
        option = input(" Please Choose an option: ")
        try:
            if option == '1':
                key = int(input("\n Enter an ID: "))
                name = input(" Enter a name: ")
                job = input(" Enter a job: ")
                age = int(input(" Enter an age: "))
                vault.insert(key, name, job, age)
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
                if vault.count == 0:
                    print(" No data in the database.")
                else:
                    for index, node in enumerate(vault.tabel):
                        while node is not None:
                            print(f'\n Index: {index}, ID: {node.key}, Employee: {node.val}')
                            node = node.next
            elif option == '5':
                print("\n Thank you for using Vault 101 Employee Database\n Goodbye, Overseer\n\n Lead Them To Paradise! - Abdulhadi")
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
