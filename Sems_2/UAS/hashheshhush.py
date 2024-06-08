# Overseer: Abdulhadi Muntashir
import os


class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(self.size)]

    def _hash(self, key):
        return hash(key) % self.size


    def insert(self, key, name, job, age):
        hash_key = self._hash(key)
        bucket = self.table[hash_key]
        for i, kv in enumerate(bucket):
            k, v = kv
            if key == k:
                bucket[i] = (key, {"name": name, "job": job, "age": age})
                return
        bucket.append((key, {"name": name, "job": job, "age": age}))

    def find(self, key):
        hash_key = self._hash(key)
        bucket = self.table[hash_key]
        for i, kv in enumerate(bucket):
            k, v = kv
            if key == k:
                return v
        return None

    def delete(self, key):
        hash_key = self._hash(key)
        key_exists = False
        bucket = self.table[hash_key]
        for i, kv in enumerate(bucket):
            k, v = kv
            if key == k:
                key_exists = True
                break
        if key_exists:
            del bucket[i]
        else:
            raise KeyError('ID {} not found'.format(key))


def main():
    vault = HashTable(111)
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
            print(" ID {} deleted".format(key))
            print(" Employee data has been removed from the database")
        elif option == '4':
            for index, bucket in enumerate(vault.table):
                for i, kv in enumerate(bucket):
                    k, v = kv
                    print(f'Index: {index}, ID: {k}, Employee: {v}')
        elif option == '5':
            print(
                " Thank you for using Vault 101 Employee Database\n Goodbye, Overseer\n Lead Them To Paradise! - Abdulhadi")
            break
        else:
            print(" Invalid option, please try again.")
        # Wait for the user to press Enter before clearing the terminal
        print("\n=================================")
        input("\nPress Enter to continue...")


if __name__ == "__main__":
    main()
