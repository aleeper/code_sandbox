

def convert_to_alt_caps(message):
    lower = message.lower()
    upper = message.upper()
    data = []
    space_offset = 0
    for i in range(len(lower)):
        if not lower[i].isalpha():
            space_offset += 1

        if (i + space_offset) % 2 == 0:
            data.append(lower[i])
        else:
            data.append(upper[i])
    return ''.join(data)

def main():
    input_str = "Pikachu"
    print(input_str)
    print(convert_to_alt_caps(input_str))
    input_str = "section is AWESOME"
    print(input_str)
    print(convert_to_alt_caps(input_str))



if __name__ == '__main__':
    main()