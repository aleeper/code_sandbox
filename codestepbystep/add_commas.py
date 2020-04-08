def break_number_into_chunks(string, chunk_size):
    # [padded_number[i:i+3] for i in range(0, len(padded_number), 3)]
    chunks = []
    for i in range(0, len(string), chunk_size):
        chunks.append(string[i : i + chunk_size])
    return chunks

def add_commas(number):
    pad_length = 3 - (len(number) % 3)
    if pad_length == 1:
        padding = "0"
    elif pad_length == 2:
        padding = "00"
    else:
        pad_length = 0
        padding = ""

    padded_number = padding + number
    chunked_number = break_number_into_chunks(padded_number, 3)
    with_commas = ','.join(chunked_number)
    return with_commas[pad_length:]

if __name__ == '__main__':

    print(add_commas("12345678"))
    print(add_commas("1"))
    print(add_commas("123"))
    print(add_commas(""))

