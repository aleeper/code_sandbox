key = 'my_var'
value = 0.234

formatted = f'{key!r:<10} = {value:+.2f}'
print(formatted)

item = ('Peanut butter', 'Jelly', 'Jam')
first, second, third = item
print(first, 'and', second)

print(*item)

snack_calories = {
'chips': 140,
'popcorn': 80,
'nuts': 190
}

for rank, (name, calories) in enumerate(snack_calories.items()):
    print(rank, name, calories)

names = ['Cecilia', 'Lise', 'Marie']
counts = [len(n) for n in names]

longest_name = None
max_count = 0
for (name, count) in zip(names, counts):
    if count > max_count:
        longest_name = name
        max_count = count

print(longest_name, max_count)
names.append('Rosalind')

import itertools
for (name, count) in itertools.zip_longest(names, counts, fillvalue=0):
    print(f'{name}: {count}')