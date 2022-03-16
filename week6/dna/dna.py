import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit(0)

    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        people = list(reader)

    listStr = list(people[0].keys())
    listStr.remove('name')
    txtObj = {}
    for i in listStr:
        txtObj[i] = 0

    # TODO: Read DNA sequence file into a varible
    with open(sys.argv[2], "r") as file:
        txt = file.read()
        for str in listStr:
            temp = txt
            temp = temp.replace(str,'@')
            for i in temp:
                if i == '@':
                    txtObj[str] += 1
        file.close()

    # print(txtObj)

    # print(people)
    for i in people:
        count = 0
        for j in listStr:
            if txtObj[j] == i[j]:
                count +=1
        if count == len(listStr):
            return i['name']

    return


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
