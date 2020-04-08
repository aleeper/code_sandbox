def collapse_sequences(message, collapse_char, collapsing = False):
    if message == '':
        return ''

    # Approach 1:    
    prepend = message[0]
    if prepend == collapse_char:
        if collapsing:
            prepend = ''
        collapsing = True
    else:
        collapsing = False

    return prepend + collapse_sequences(message[1:], collapse_char, collapsing)

    # Approach 2:
    # c = message[0]
    # if c == collapse_char:
    #     if collapsing:
    #         return collapse_sequences(message[1:], collapse_char, True)
    #     else:
    #         return c + collapse_sequences(message[1:], collapse_char, True)

    # return c + collapse_sequences(message[1:], collapse_char, False)
    


def main():
    print(collapse_sequences("aabaaccaaaaaada", 'a'))


if __name__ == '__main__':
    main()