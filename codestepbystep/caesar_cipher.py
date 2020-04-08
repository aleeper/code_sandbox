def prompt_for_user_inputs():
    message = input("Your message? ")
    key = input("Encoding key? ")
    return message, int(key)

def get_test_input():
    return "attack Zerg at DAWN", int("3")

def encode_string(message, shift):
    letters = 'abcdefghijklmnopqrstuvwxyz'.upper()
    message_lower = message.upper()
    data = []
    for c in message_lower:
        if c in letters:
            index = (letters.index(c) + shift) % 26
            data.append(letters[index])
        else:
            data.append(c)
    return ''.join(data)

def main():
    # Much easier to develop if we separate user input from
    # the algorithm.
    message, key = prompt_for_user_inputs()
    # message, key = get_test_input()
    encoded_message = encode_string(message, key)
    print(encoded_message)

    # restored_message = encode_string(encoded_message, -key)
    # print(restored_message)


if __name__ == '__main__':
    main()