def main():
    txt = input("Text: ")
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
    print(wordCount,'  ',character,'  ',sentence)

main()

# Recall that the Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8,
# where L is the average number of letters per 100 words in the text,
# and S is the average number of sentences per 100 words in the text.