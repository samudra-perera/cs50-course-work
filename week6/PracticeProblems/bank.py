#Ask for the greeting
greeting = input("Greeting: ")

#Strip any leading space
greeting = greeting.strip().split()
greeting = greeting[0].lower()

if 'hello' in greeting:
    print('$0')
elif 'h' == greeting[0]:
    print('$20')
else:
    print('$100')
