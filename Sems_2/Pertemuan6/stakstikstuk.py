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


# Initialize a rolling buffer of size 5
buffer = RollingBuffer(5)

# Add some data to the buffer
for i in range(10):
    buffer.add(i)
    print(buffer.get())  # Output: the last 5 items added
