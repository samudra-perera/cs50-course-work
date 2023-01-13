# TODO

#Get text input from the user
text = input("Text: ")
text = text.lower()
#Initialize the variables
words = 1
sentences = 0
letters = 0

for letter in text:
    if(letter == ' '):
        words += 1
    elif letter == '?' or letter == '.' or letter == '!':
        sentences += 1
    #counting all non alpha characters
    elif ord(letter) < 96 or ord(letter) > 123:
        letters += 1
    else:
        continue

alpha_char = len(text) - words - sentences - letters + 1
el = (alpha_char / words) * 100
es = (sentences / words) * 100

index = (0.0588 * el) - (0.296 * es) - 15.8
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {int(round(index, 0))}")


#passed 10/10 tests and 88% on the styling