import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


#Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    rows = list(reader)
    #Declare a new dictionary
    new_cases = {}
    #For the rows in the list reverse them and add a key value pair for the state
    for row in reversed(rows):
        new_cases[row['state']] = []
    #Add the first 15 to the list
    for row in reversed(rows):
        if(len(new_cases[row['state']]) > 14):
            continue
        new_cases[row['state']].append(row['cases'])

    #iterate through each state
    for state in new_cases:
        #counter for keeping track of the indexes
        counter = 0
        #Iterating through the list within the dictionary
        for cases in new_cases[state]:
            #Ensuring that the for loop does not extend past the last index
            if counter > 13:
                continue
            #Subtracting the current day from the previous to get the daily amount
            new_cases[state][counter] = int(new_cases[state][counter]) - int(new_cases[state][counter + 1])
            #Add one to the counter
            counter+=1
        #Remove the last element of the list
        new_cases[state].pop()
    return new_cases


#Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    #Iterate through the list of states inputted by the user
    for state in states:
        #counter for the first 7 days and second counter for the second 7 days
        counter7 = 0
        counter14 = 7
        average7 = 0
        average14 = 0
        difference = 0
        #Adding the cases of the selected states and finding the averages
        for cases in new_cases[state]:
            if counter14 == 14:
                break
            elif counter7 < 7:
                average7 += new_cases[state][counter7]
                counter7+=1
            else:
                average14 += new_cases[state][counter14]
                counter14+=1
        #Calculating the averages
        average7 = average7/7
        average14 = average14/7
        #Calculating the difference, if the second 7 day avg is 0 pass
        try:
            difference = (average7 - average14)/(average14) * 100
        except ZeroDivisionError:
            pass
        #Conditionals for difference
        if difference > 0:
            print(f"{state} had a 7-day average of {average7} and a increase of {difference:.2f}%")
        elif difference < 0:
            print(f"{state} had a 7-day average of {average7} and a decrease of {difference:.2f}%")
        else:
            print(f"{state} had a 7-day average of {average7} and no difference")


main()