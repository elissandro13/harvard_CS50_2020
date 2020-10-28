from cs50 import *
import sys

#  15 -> 34 or 37 visa
# 16 -> 51,52,54,54,55 mastercard
# 13 or 16 -> 4 visa


def sumProducts(num):

    sum = 0

    while num > 0:
        sum += num % 10
        num = num // 10

    return sum


while True:
    cardNumber = get_int("Number: ")
    if cardNumber > 0:
        break
# length
tam = len(str(cardNumber))
if tam < 13 or tam > 16:
    print("INVALID")
    sys.exit()

cardArray = []
c = 0

# invert

while c < tam:
    cardArray.insert(c, cardNumber % 10)
    cardNumber = cardNumber // 10
    c += 1

sumOfProducts = 0
products = 0
i = 1

# sum par
for i in range(tam):
    if i % 2 != 0:
        product = cardArray[i] * 2
        sumOfProducts += sumProducts(product)
# sum even
for i in range(tam):
    if i % 2 == 0:
        sumOfProducts += cardArray[i]

# take digits
firstDigit = cardArray[tam-1]
secondDigit = cardArray[tam-2]
twoDigits = int(str(cardArray[tam-1]) + str(cardArray[tam-2]))

# check valid
if (sumOfProducts % 10 == 0):

    if (tam == 15 and firstDigit == 3 and (secondDigit == 4 or secondDigit == 7)):

        print("AMEX")

    elif (tam == 16 and (twoDigits >= 51 and twoDigits <= 55)):

        print("MASTERCARD")

    elif ((tam == 13 or tam == 16) and firstDigit == 4):

        print("VISA")

    else:

        print("INVALID\n")

else:

    print("INVALID")