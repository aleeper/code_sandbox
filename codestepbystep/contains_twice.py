

def contains_twice(message, char):
    # return message.count(char) >= 2
    count = 0
    for i in message:
        if i == char:
            count += 1
    return count >= 2


def main():
    print(contains_twice("hello", 'l'))
    print(contains_twice("helo", 'l'))


if __name__ == '__main__':
    main()