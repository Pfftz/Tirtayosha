import random

numbers = []
for _ in range(1000):
    number = random.randint(1, 100)
    numbers.append(number)

with open('random_numbers.txt', 'w') as f:
    f.write(str(numbers))
