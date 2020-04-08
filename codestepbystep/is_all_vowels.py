def is_vowel(c):
    return len(c) == 1 and c.lower() in 'aeiou'


def is_all_vowels(message):
    for c in message:
        if not is_vowel(c) and not c in '-_':
            return False
    return True


def main():
    message = "ei_e_io"
    print(message)
    print(is_all_vowels(message))

    message = "banana"
    print(message)
    print(is_all_vowels(message))


if __name__ == '__main__':
    main()