'''tutorial python wak'''

fruits = ['apple', 'banana', 'cherry']
text = 'cak kocak'

#iteration by item
for x in fruits:
    print(x)

#slice operator
print(text[0:5:2])

#insert item in list
fruits.insert(1, 'orange')
fruits.append('mango')
fruits[2:2] = 'grape'
print(fruits)
