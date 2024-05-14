'''vault 101 employee database using hash table'''
import os


class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(self.size)]

    def _hash(self, key):
        return hash(key) % self.size


    def insert(self, key, name, job, age, sex, eyes, hair, status):
        hash_key = self._hash(key)
        bucket = self.table[hash_key]
        for i, kv in enumerate(bucket):
            k, v = kv
            if key == k:
                bucket[i] = (key, {"name": name, "job": job, "age": age, "sex": sex,
                             "eyes": eyes, "hair": hair, "status": status})
                return
        bucket.append((key, {"name": name, "job": job, "age": age, "sex": sex,
                             "eyes": eyes, "hair": hair, "status": status}))

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
            print(" ID {} deleted".format(key))
            print(" Employee data has been removed from the database")
        elif option == '4':
            print(
                " Thank you for using Vault 101 Employee Database\n Goodbye, Overseer\n")
            break
        else:
            print(" Invalid option, please try again.")
        # Wait for the user to press Enter before clearing the terminal
        print("\n=================================")
        input("\nPress Enter to continue...")


if __name__ == "__main__":
    main()
