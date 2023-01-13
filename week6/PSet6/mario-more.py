# TODO

while True:
    #Input validation
    try:
        height = int(input('Height: '))
    except ValueError:
        continue

    if height > 0 and height < 9:
        break

for i in range(height):
    right = '#' * (i + 1)
    left = ' ' * ((height-1) - i) + '#' * (i + 1)
    print(left + '  ' + right)

#Passed 9/9 tests and 94% on the styling