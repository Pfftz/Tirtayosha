# Open the file
with open('D:\\Alprot\\Sems_2\\Pertemuan1\\random_numbers.txt', 'r') as f:
    # Read the content
    content = f.read()

# Remove the brackets and split by comma
names = content.replace('[', '').replace(']', '').split(',')

# Remove leading/trailing whitespaces and quotes
names = [name.strip().strip('\'"') for name in names]

# Write the names to a new file, one name per line
with open('new_numbers.txt', 'w') as f:
    for name in names:
        f.write(name + '\n')

