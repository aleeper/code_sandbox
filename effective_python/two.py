# Item 11: Know How to Slice Sequences
a = list(range(5))
print(a)
a[2:3] = range(5)
print(a)
a[2:5] = [0]
print(a)
print(list(range(0, 10, 2)))

# Item 12: Avoid Slicing and Striding in the Same Expression
print(list(range(0, 10)[3::3]))
print(list(range(0, 10))[::2][1:-1])

# Item 13: Prefer Catch-All Unpacking Over Slicing
short_list = [1, 2]
first, second, *others = short_list
print(first, second, others)
first, *others, last = short_list
print(first, others, last)

def generate_csv():
    yield ('Date', 'Value')
    yield ('2020-01-01', 1)
    yield ('2020-01-02', 2)
    yield ('2020-01-03', 3)
    yield ('2020-01-04', 4)
    yield ('2020-01-05', 5)
    yield ('2020-01-06', 6)
    yield ('2020-01-07', 7)
    yield ('2020-01-08', 8)
    yield ('2020-01-09', 9)

header, *rows = generate_csv()
print('CSV Header:', header)
print('Row count:', len(rows))

# Item 14: Sort by Complex Criteria Using the key Parameter
class Tool:
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight

    def __repr__(self):
        return f'Tool({self.name!r}, {self.weight})'


tools = [
    Tool('level', 3.5),
    Tool('hammer', 1.25),
    Tool('screwdriver', 0.5),
    Tool('chisel', 0.25)    
]

tools = [
    Tool('drill', 4),
    Tool('sander', 4),
    Tool('circular saw', 5),
    Tool('jackhammer', 40)    
]

tools.sort(key=lambda x: x.name)
print('By name:\n' + '\n'.join([t.__repr__() for t in tools]))
tools.sort(key=lambda x: (-x.weight, x.name))
print('By weight descending then name ascending:\n' +
    '\n'.join([t.__repr__() for t in tools]))

tools.sort(key=lambda x: x.name)
tools.sort(key=lambda x: x.weight, reverse=True)
print('By weight descending then name ascending with multiple sorts:\n' +
    '\n'.join([t.__repr__() for t in tools]))

places = ['home', 'work', 'New York', 'Paris']
places.sort()
print(places)
places.sort(key=lambda x: x.lower())
print(places)

# Item 15: Be Cautious When Relying on Dict Insertion Order

# Item 16:Prefer get Over in and KeyError to Handle Missing Dictionary Keys

orders = ['sesame', 'everything', 'plain', 'sesame', 'sesame', 'everything']
counts = {}

for item in orders:
    count = counts.get(item, 0)
    counts[item] = count + 1

print(sorted([*counts.items()], key=lambda x: x[0]))
print(sorted([*counts.items()], key=lambda x: x[1]))

# Item 17: Prefer defaultdict over setdefault

visits = {
    'Mexico': {'Tulum', 'Puerto Vallarta'},
    # 'Japan': {'Hakone'}
}

if (japan := visits.get('Japan')) is None:
    visits['Japan'] = japan = set()
japan.add('Kyoto')

print(visits)

from collections import defaultdict

class Visits:
    def __init__(self):
        self.data = defaultdict(set)

    def add(self, country, city):
        self.data[country].add(city)

    def __repr__(self):
        return dict(self.data).__repr__()

visits = Visits()
visits.add('England', 'Bath')
visits.add('England', 'London')
print(visits)