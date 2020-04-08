import matplotlib.pyplot as plt
import numpy as np
import csv

def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass
 
    try:
        import unicodedata
        unicodedata.numeric(s)
        return True
    except (TypeError, ValueError):
        pass
 
    return False


def process_columns(age, weight):
    pairs = list(zip(age, weight))
    filtered = [(int(t[0]), float(t[1])) for t in pairs 
                if is_number(t[0]) and is_number(t[1])]
    flat = list(zip(*filtered))
    return flat


with open('baby_data.csv', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    columns = list(zip(*reader))
    perrin_data = process_columns(columns[1], columns[4])
    tobin_data = process_columns(columns[7], columns[10])


# with plt.xkcd():
if True:
    # Based on "Stove Ownership" from XKCD by Randall Munroe
    # https://xkcd.com/418/

    fig = plt.figure()
    ax = fig.add_axes((0.1, 0.2, 0.8, 0.7))
    # ax.spines['right'].set_color('none')
    # ax.spines['top'].set_color('none')
    ax.set_xticks(np.arange(0, 100, step=7))
    # ax.set_yticks([])
    ax.set_xlim([0, 30])
    ax.set_ylim([4, 14])

    # ax.annotate(
    #     'THE DAY I REALIZED\nI COULD COOK BACON\nWHENEVER I WANTED',
    #     xy=(70, 1), arrowprops=dict(arrowstyle='->'), xytext=(15, -10))

    ax.scatter(perrin_data[0], perrin_data[1])
    ax.scatter(tobin_data[0], tobin_data[1])
    # ax.plot(tobin_weight)
    ax.legend(['Perrin', 'Tobin'])
    ax.grid(True)

    ax.set_xlabel('Age (days)')
    ax.set_ylabel('Weight (lbs)')

    # fig.text(
    #     0.5, 0.05,
    #     '"Stove Ownership" from xkcd by Randall Munroe',
    #     ha='center')

    plt.show()