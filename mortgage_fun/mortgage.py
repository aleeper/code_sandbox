import matplotlib.pyplot as plt
import numpy as np

# Rates pulled on 2020-03-27 from
# https://mortgage.nusenda.org/Wizard/LoanConsultant.asp
rates_30 = [
    {'payment': 747, 'closing': 7425},
    # {'payment': 759, 'closing': 5850},
    # {'payment': 771, 'closing': 4275},
    # {'payment': 783, 'closing': 3150},
    {'payment': 796, 'closing': 2475},
    # {'payment': 821, 'closing': 1350},
    {'payment': 859, 'closing': 225}
]

rates_15 = [
    {'rate': 2.375, 'points': 1.75  , 'apr': 2.770, 'payment': 1190, 'closing': 7200},
    # {'rate': 2.500, 'points': 1     , 'apr': 2.788, 'payment': 1200, 'closing': 5850},
    # {'rate': 2.625, 'points': 0.625 , 'apr': 2.859, 'payment': 1211, 'closing': 5175},
    # {'rate': 2.750, 'points': 0.25  , 'apr': 2.931, 'payment': 1222, 'closing': 4500},
    {'rate': 2.875, 'points': -0.125, 'apr': 3.020, 'payment': 1232, 'closing': 3825},
    # {'rate': 3.000, 'points': -0.625, 'apr': 3.146, 'payment': 1243, 'closing': 2925},
    # {'rate': 3.125, 'points': -1    , 'apr': 3.271, 'payment': 1254, 'closing': 2250},
    # {'rate': 3.250, 'points': -1.25 , 'apr': 3.397, 'payment': 1265, 'closing': 1800},
    {'rate': 3.375, 'points': -1.5  , 'apr': 3.522, 'payment': 1276, 'closing': 1350}
]

def present_cost(payment, closing, months, annual_inflation):
    monthly_inflation = (1 + annual_inflation)**(1/12)
    present_value = closing
    for month in range(months):
        present_value += payment/(monthly_inflation ** month)
    return present_value

def add_costs(rate_data, months, annual_inflation):
    for entry in rate_data:
        payment, closing = entry['payment'], entry['closing']
        nominal_cost = []
        real_cost = []
        for month in range(months + 1):
            real_cost.append((month, present_cost(
                    payment, closing, month, annual_inflation)))
            nominal_cost.append((month, present_cost(
                    payment, closing, month, 0)))
        entry['real_cost'] = real_cost
        entry['nominal_cost'] = nominal_cost

def get_graphing_data(rate_data):
    all_data = {}
    for entry in rate_data:
        label = entry['payment']
        data = {'label': label}
        data['real_months'], data['real_cost'] = zip(*entry['real_cost'])
        data['nominal_months'], data['nominal_cost'] = zip(*entry['nominal_cost'])
        all_data[label] = data
    return all_data
  
ANNUAL_INFLATION = 0.037

add_costs(rates_30, 12 * 30, ANNUAL_INFLATION)
add_costs(rates_15, 12 * 15, ANNUAL_INFLATION)

data_15 = get_graphing_data(rates_15)
data_30 = get_graphing_data(rates_30)

fig = plt.figure()

ax1 = fig.add_subplot(121)
ax2 = fig.add_subplot(122)
ax1.title.set_text('"Nominal" dollars paid back for different monthly payments')
ax2.title.set_text('"Real" dollars paid back in today\'s dollars (avg. 3.7% inflation)')

all_data = dict(data_30)
all_data.update(data_15)

for data in all_data.values():
    ax1.plot(data['nominal_months'], data['nominal_cost'], label=data['label'])
# Reset colors so they match.
plt.gca().set_prop_cycle(None)    
for data in all_data.values():
    ax2.plot(data['real_months'], data['real_cost'], label=data['label'])

ax1.legend()
ax1.grid(True)
ax1.set_xlabel('months')
ax1.set_ylabel('nominal dollars')

ax2.legend()
ax2.grid(True)
ax2.set_xlabel('months')
ax2.set_ylabel('real dollars (present-day)')

ax1.set_xlim(0, 360)
ax2.set_xlim(0, 360)
ax1.set_ylim(0, 300000)
ax2.set_ylim(0, 300000)

ax1.axvline(72, ls='--')
ax2.axvline(72, ls='--')

ax1.axhline(180000, ls='--')
ax2.axhline(180000, ls='--')

ax2.annotate(
    'Lower monthly payment == higher closing costs,\nbut cheaper if you keep the loan >6 years.',
    xy=(21, 22300), arrowprops=dict(arrowstyle='->'), xytext=(80, 12000))

ax1.annotate(
    'Loan Amount = $180,000',
    xy=(240, 180000), arrowprops=dict(arrowstyle='->'), xytext=(200, 130000))

ax1.annotate(
    '6 years',
    xy=(75, 58000), arrowprops=dict(arrowstyle='->'), xytext=(100, 40000))

ax1.annotate(
    '15-year mortgage is "cheaper"',
    xy=(185, 230000), arrowprops=dict(arrowstyle='->'), xytext=(120, 250000))

ax2.annotate(
    'With inflation, present-day "real" cost\nis similar for 15- and 30-year.',
    xy=(185, 185000), arrowprops=dict(arrowstyle='->'), xytext=(120, 210000))

plt.show()
