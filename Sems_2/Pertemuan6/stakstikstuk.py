'''Pertemuan 6 Struktur Data-stack'''
from collections import deque


class RollingBuffer:
    def __init__(self, size):
        self.size = size
        self.buffer = deque(maxlen=size)

    def add(self, item):
        self.buffer.append(item)

    def get(self):
        return list(self.buffer)

    def average(self):
        if not self.buffer:
            return 0
        return sum(self.buffer) / len(self.buffer)


# Initialize a rolling buffer with size from user input
buffer_size = int(input("Enter the size of the buffer: "))
buffer = RollingBuffer(buffer_size)

while True:
    # Add data to the buffer from user input
    data = input("Enter a number to add to the buffer (or 'q' to quit): ")
    if data.lower() == 'q':
        break
    buffer.add(int(data))
    print(f"Buffer: {buffer.get()}")  # Output: the last N items added
    # Output: average of the last N items
    print(f"Average: {buffer.average()}")
