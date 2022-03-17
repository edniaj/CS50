
from cs50 import get_string

def main():
    txt = get_string("Text: ")
    wordCount = 1
    character = 0
    sentence = 0
    for word in txt:
        if word ==  ' ':
            wordCount += 1
        if word.isalpha():
            character +=1
        if word in ['?','!','.']:
            sentence += 1
    temp =  100/wordCount
    # i. e. word = 4, temp = 25, 5 char in 4 word. 125 char in 100 word.  temp * char = 25 * 5 = 125. 5 char in 500 word. tmp = 0.2,
    L = temp * character
    S = temp * sentence
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index >=16:
        print('Grade ',16,'+\n')
        return
    elif index <1:
        print('Before Grade 1')
    else:
        print('Grade ',round(index),'\n')
main()

# Recall that the Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8,
# where L is the average number of letters per 100 words in the text,
# and S is the average number of sentences per 100 words in the text.