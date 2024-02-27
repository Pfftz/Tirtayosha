'''pertemuan 1 struktur data'''
# Open the file in read mode ('r')
with open('D:\\Alprot\\Sems_2\\Pertemuan1\\databases.txt', 'r') as file:
    content = file.read()

import random

# Assuming 'content' is your list
content = content.split()  # Split the content into a list if it's a string

# Generate a list of 100 values
values = [random.randint(1, 100) for _ in range(len(content))]

# Create a dictionary
dictionary = {key: value for key, value in zip(content, values)}


