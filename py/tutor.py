'''tutorial python wak'''

fruits = ['apple', 'banana', 'cherry']
text = 'cak kocak'

# iteration by item
for x in fruits:
    print(x)

# slice operator
print(text[0:5:2])

# insert item in list
fruits.insert(1, 'orange')
fruits.append('mango')
fruits[3:3] = ['grape']
print(fruits)

numbers = [1, 2, 3, 4, 5]
squares = [n**2 for n in numbers if n % 2 == 1]  # square of odd numbers
print(squares)
