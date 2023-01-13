# TODO

#input validation
while True:
    try:
        card_number = int(input("Card No: "))
    except ValueError:
        continue

    if card_number > 0:
        break

#create an array from the inputted credit card number
credit_array = [int(x) for x in str(card_number)]

sum1 = 0
sum2 = 0


for num in range(len(credit_array) - 2, -1, -2):
    if credit_array[num] * 2 < 10:
        sum1 += credit_array[num] * 2
    else:
        temp = [int(x) for x in str(credit_array[num] * 2)]
        for num in range(0, len(temp), 1):
            sum1 += temp[num]

for num in range(len(credit_array) - 1, -1, -2):
    sum2 += credit_array[num]

firstTwoDigits = int(str(credit_array[0]) + str(credit_array[1]))


if (sum1 + sum2) % 10 != 0:
    print("INVALID")
elif (len(credit_array) == 13 or len(credit_array) == 16) and credit_array[0] == 4:
    print("VISA")
elif len(credit_array) == 16 and (50 < firstTwoDigits < 56):
    print("MASTERCARD")
elif len(credit_array) == 15 and (firstTwoDigits == 34 or firstTwoDigits == 37):
    print("AMEX")
else:
    print("INVALID")

# Passed 14/14 tests and 95% styling