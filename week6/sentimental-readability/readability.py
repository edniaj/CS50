def main():
    txt = input("Text: ")
    wordCount = 1
    for word in txt:
        if word ==  ' ':
            wordCount += 1
    print(wordCount)

main()