def main():
    txt = input("Text: ")
    wordCount = 1
    character = 0
    for word in txt:
        if word ==  ' ':
            wordCount += 1
        if word.isalpha():
            character +=1
    print(wordCount,'  ',character)

main()