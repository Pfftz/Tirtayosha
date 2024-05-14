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

    def test_delete_multiple(self):
        for i in range(10):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
        for i in range(10):
            self.vault.delete(i)
            employee = self.vault.find(i)
            self.assertIsNone(employee)

    def test_insert_duplicate_key(self):
        self.vault.insert(1, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        self.vault.insert(1, "Jane Doe", "Scientist", 32, "Female", "Green", "Blonde", "Alive")
        employee = self.vault.find(1)
        self.assertEqual(employee["name"], "Jane Doe")

    def test_find_nonexistent_key(self):
        employee = self.vault.find(1)
        self.assertIsNone(employee)

    def test_delete_nonexistent_key(self):
        self.vault.delete(1)  # Should not raise an error

    def test_resize(self):
        for i in range(101):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
        self.assertEqual(self.vault.size, 202)

    def test_insert_after_resize(self):
        for i in range(101):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
        self.vault.insert(101, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        employee = self.vault.find(101)
        self.assertEqual(employee["name"], "John Doe")

    def test_delete_after_resize(self):
        for i in range(101):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
        self.vault.delete(50)
        employee = self.vault.find(50)
        self.assertIsNone(employee)

    def test_insert_and_find_different_types(self):
        self.vault.insert("1", "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        employee = self.vault.find("1")
        self.assertEqual(employee["name"], "John Doe")

    def test_delete_different_types(self):
        self.vault.insert("1", "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        self.vault.delete("1")
        employee = self.vault.find("1")
        self.assertIsNone(employee)


    def test_collision_insert_and_find(self):
        self.vault.insert(1, "John Doe", "Engineer", 30,
                          "Male", "Blue", "Black", "Alive")
        self.vault.insert(102, "Jane Doe", "Scientist", 32, "Female",
                          "Green", "Blonde", "Alive")  # Collision with key 1
        employee = self.vault.find(102)
        self.assertEqual(employee["name"], "Jane Doe")

    def test_collision_delete(self):
        self.vault.insert(1, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        self.vault.insert(102, "Jane Doe", "Scientist", 32, "Female", "Green", "Blonde", "Alive")  # Collision with key 1
        self.vault.delete(102)
        employee = self.vault.find(102)
        self.assertIsNone(employee)

    def test_collision_insert_multiple(self):
        for i in range(10):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
            self.vault.insert(i+101, f"Employee {i+101}", "Scientist", 30+i, "Female", "Green", "Blonde", "Alive")  # Collision with key i
        for i in range(10):
            employee = self.vault.find(i+101)
            self.assertEqual(employee["name"], f"Employee {i+101}")

    def test_collision_delete_multiple(self):
        for i in range(10):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
            self.vault.insert(i+101, f"Employee {i+101}", "Scientist", 30+i, "Female", "Green", "Blonde", "Alive")  # Collision with key i
        for i in range(10):
            self.vault.delete(i+101)
            employee = self.vault.find(i+101)
            self.assertIsNone(employee)

    def test_collision_insert_duplicate_key(self):
        self.vault.insert(1, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        self.vault.insert(102, "Jane Doe", "Scientist", 32, "Female", "Green", "Blonde", "Alive")  # Collision with key 1
        self.vault.insert(102, "Jack Doe", "Doctor", 34, "Male", "Brown", "Brown", "Alive")  # Duplicate key
        employee = self.vault.find(102)
        self.assertEqual(employee["name"], "Jack Doe")

    def test_collision_find_nonexistent_key(self):
        self.vault.insert(1, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        employee = self.vault.find(102)  # Nonexistent key that would collide with key 1
        self.assertIsNone(employee)

    def test_collision_delete_nonexistent_key(self):
        self.vault.insert(1, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        self.vault.delete(102)  # Nonexistent key that would collide with key 1

    def test_collision_resize(self):
        for i in range(101):
            self.vault.insert(
                i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
            self.vault.insert(i+101, f"Employee {i+101}", "Scientist", 30+i,
                              "Female", "Green", "Blonde", "Alive")  # Collision with key i
        self.assertEqual(self.vault.size, 404)

    def test_collision_insert_after_resize(self):
        for i in range(101):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
        self.vault.insert(101, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        self.vault.insert(202, "Jane Doe", "Scientist", 32, "Female", "Green", "Blonde", "Alive")  # Collision with key 101
        employee = self.vault.find(202)
        self.assertEqual(employee["name"], "Jane Doe")

    def test_collision_delete_after_resize(self):
        for i in range(101):
            self.vault.insert(i, f"Employee {i}", "Engineer", 30+i, "Male", "Blue", "Black", "Alive")
        self.vault.insert(101, "John Doe", "Engineer", 30, "Male", "Blue", "Black", "Alive")
        self.vault.insert(202, "Jane Doe", "Scientist", 32, "Female", "Green", "Blonde", "Alive")  # Collision with key 101
        self.vault.delete(202)
        employee = self.vault.find(202)
        self.assertIsNone(employee)


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
