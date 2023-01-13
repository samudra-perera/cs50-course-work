from pyfiglet import Figlet
import sys
import random

figlet = Figlet()
fonts = figlet.getFonts()

#Conditional checks
#If no font give set font choice to random
if len(sys.argv) == 1:
    figlet.setFont(font=random.choice(fonts))
#if font is given check to see if arguments are correct and that the font exists
elif len(sys.argv) == 3 and (sys.argv[1] == '-f' or sys.argv[1] == '--font') and sys.argv[2] in fonts:
    figlet.setFont(font=sys.argv[2])
else:
    print("Invalid Usage")
    sys.exit(1)

text = input("Input: ")
print(figlet.renderText(text))




