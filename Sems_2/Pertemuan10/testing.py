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


if __name__ == '__main__':
    unittest.main()
