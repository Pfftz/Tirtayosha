import unittest
from hashlagi import HashTable


class TestHashTable(unittest.TestCase):
    def setUp(self):
        self.vault = HashTable(101)

    def test_insert_and_find(self):
        self.vault.insert(1, "John Doe", "Engineer", 30,
                          "Male", "Blue", "Black", "Alive")
        employee = self.vault.find(1)
        self.assertEqual(employee["name"], "John Doe")
        self.assertEqual(employee["job"], "Engineer")
        self.assertEqual(employee["age"], 30)
        self.assertEqual(employee["sex"], "Male")
        self.assertEqual(employee["eyes"], "Blue")
        self.assertEqual(employee["hair"], "Black")
        self.assertEqual(employee["status"], "Alive")

    def test_delete(self):
        self.vault.insert(1, "John Doe", "Engineer", 30,
                          "Male", "Blue", "Black", "Alive")
        self.vault.delete(1)
        employee = self.vault.find(1)
        self.assertIsNone(employee)


    def test_insert_and_find_multiple(self):
        for i in range(10):
            self.vault.insert(
                i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
            employee = self.vault.find(i)
            self.assertEqual(employee["name"], f"Employee {i}")
            self.assertEqual(employee["job"], "Engineer")
            self.assertEqual(employee["age"], 30+i)
            self.assertEqual(employee["sex"], "Male")
            self.assertEqual(employee["eyes"], "Blue")
            self.assertEqual(employee["hair"], "Black")
            self.assertEqual(employee["status"], "Alive")

    def test_distribution(self):
        # Insert a large number of keys into the hash table
        for i in range(1000):
            self.vault.insert(i, 'John Doe', 'Engineer', 30,
                              'Male', 'Blue', 'Black', 'Alive')

        # Calculate the length of the linked list at each slot in the hash table
        lengths = [0 for _ in range(self.vault.size)]
        for i in range(self.vault.size):
            node = self.vault.table[i]
            while node is not None:
                lengths[i] += 1
                node = node.next

        # Calculate the mean and standard deviation of the lengths
        mean = sum(lengths) / len(lengths)
        stddev = (sum((x - mean) ** 2 for x in lengths) / len(lengths)) ** 0.5

        print('\nMean:', mean)
        print('Standard deviation:', stddev)
        
if __name__ == "__main__":
    unittest.main()
