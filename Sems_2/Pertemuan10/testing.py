import unittest
from vault101_hashtable import HashTable


class TestHashTable(unittest.TestCase):
    def setUp(self):
        self.vault = HashTable(101)

    def test_insert(self):
        self.vault.insert(1, 'John Doe', 'Engineer', 30,
                          'Male', 'Blue', 'Black', 'Alive')
        bucket = self.vault.table[self.vault._hash(1)]
        self.assertEqual(bucket[0], (1, {"name": 'John Doe', "job": 'Engineer', "age": 30,
                         "sex": 'Male', "eyes": 'Blue', "hair": 'Black', "status": 'Alive'}))

    def test_find(self):
        self.vault.insert(1, 'John Doe', 'Engineer', 30,
                          'Male', 'Blue', 'Black', 'Alive')
        self.assertIsNone(self.vault.find(2))

    def test_delete(self):
        self.vault.insert(1, 'John Doe', 'Engineer', 30,
                          'Male', 'Blue', 'Black', 'Alive')
        self.vault.delete(1)
        self.assertIsNone(self.vault.find(1))

    def test_distribution(self):
        # Insert a large number of keys into the hash table
        for i in range(1000):
            self.vault.insert(i, 'John Doe', 'Engineer', 30,
                              'Male', 'Blue', 'Black', 'Alive')

        # Calculate the length of the list at each slot in the hash table
        lengths = [len(self.vault.table[i]) for i in range(self.vault.size)]

        # Calculate the mean and standard deviation of the lengths
        mean = sum(lengths) / len(lengths)
        stddev = (sum((x - mean) ** 2 for x in lengths) / len(lengths)) ** 0.5

        print('\nMean:', mean)
        print('Standard deviation:', stddev)


if __name__ == '__main__':
    unittest.main()
