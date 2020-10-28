from cs50 import *

while True:
    amount = get_float("Change owed: ")
    if amount > 0:
        break
amount = round(amount*100)
count = 0
value = [25, 10, 5, 1]
for coin in value:
    count += amount // coin
    amount = amount % coin

print(count)