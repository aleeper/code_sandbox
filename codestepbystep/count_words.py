def count_words(message):
    #return len(message.split())
    # words = []
    count = 0
    activeWord = False
    for c in message:
        if c.isspace():
            activeWord = False
        else:
            if not activeWord:
                # words.append([])
                count += 1
                activeWord = True
            # words[-1].append(c)
    return count #len(words)


def main():
    message = "What is your name?"
    print(message)
    print(count_words(message))

    message = "  Howwdy  doody?   "
    print(message)
    print(count_words(message))


if __name__ == '__main__':
    main()