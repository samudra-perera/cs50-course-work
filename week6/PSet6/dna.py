import csv
import sys


def main():

    # TODO: Check for command-line usage
        if(len(sys.argv) != 3):
            print("Usage: python dna.py data.csv sequence.txt")
            sys.exit(1)

    # TODO: Read database file into a variable
        with open(sys.argv[1], 'r') as file:
            reader = csv.DictReader(file)
            database = list(reader)

    # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2], 'r') as file:
            sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    #Create a dictionary of matches to keep count of the total amount of the substring in the DNA Sequence
        match = {}
        count = 0
        for key in database[0]:
            if count == 0:
                count += 1
                continue
            match[key] = 0
            count += 1

    #For each key check the longest_match subsequence
        for key in match:
            match[key] = longest_match(sequence, key)

    # TODO: Check database for matching profiles
        #Go through every row of the database list
        for row in database:
            counter = 0
            #Go through all keys and match
            for key in match:
                #if the value stored match[key] is equivalent to the
                if int(row[key]) == match[key]:
                    counter += 1
                    #if the counter is equal to the length of match dictionary return the name
                    if counter == len(match):
                        return print(row['name'])
                # To increase the runtime if the key values do not match break the loop and go to next row
                else:
                    break
        #If not matches
        return print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

#Passed 21/21 tests but 62% on styling due to indentation error from the start