def get_string_count_to_by(to, by):
    if by < 1:
        raise ValueError("'by' must be > 0")
    if to < 1:
        raise ValueError("'to' must be > 0")
    if to <= by:
        return str(to)
    return get_string_count_to_by(to - by, by) + ", " + str(to)

def count_to_by(to, by):
    print(get_string_count_to_by(to, by))

def main():
    count_to_by(10,1)
    count_to_by(34,5)
    count_to_by(17,3)


if __name__ == '__main__':
    main()
