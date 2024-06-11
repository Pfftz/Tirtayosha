# Overseer: Abdulhadi Muntashir
import os


class tabelHashing:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(self.size)]

    def _hush(self, key):
        return hash (key) % self.size


    def insertShuju(self, key, xingming, shigoto, age):
        hush_key = self._hush(key)
        ember = self.table[hush_key]
        for i, kv in enumerate(ember):
            k, v = kv
            if key == k:
                ember[i] = (key, {"name": xingming, "job": shigoto, "age": age})
                return
        ember.append((key, {"name": xingming, "job": shigoto, "age": age}))

    def findShuju(self, key):
        hush_key = self._hush(key)
        ember = self.table[hush_key]
        for i, kv in enumerate(ember):
            k, v = kv
            if key == k:
                return v
        return None

    def deleteShuju(self, key):
        hush_key = self._hush(key)
        key_exists = False
        ember = self.table[hush_key]
        for i, kv in enumerate(ember):
            k, v = kv
            if key == k:
                key_exists = True
                break
        if key_exists:
            del ember[i]
        else:
            raise KeyError('ID {} not found'.format(key))


def main():
    vault = tabelHashing(111)
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')  # ngeberersihin terminal
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
            xingming = input(" Enter a name: ")
            shigoto = input(" Enter a job: ")
            age = int(input(" Enter an age: "))
            vault.insertShuju(key, xingming, shigoto, age)
        elif option == '2':
            key = int(input(" Enter a ID: "))
            result = vault.findShuju(key)
            if result is not None:
                print(" Found: ", result)
            else:
                print(" ID not found.")
        elif option == '3':
            key = int(input(" Enter a ID: "))
            vault.deleteShuju(key)
            print(" ID {} deleted".format(key))
            print(" Employee data has been removed from the database")
        elif option == '4':
            for index, ember in enumerate(vault.table):
                for i, kv in enumerate(ember):
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
