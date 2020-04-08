import os


def crawl(filename, indent = ""):
    files = os.listdir(filename)
    print(files)

def main():
    crawl("/Users/leeper/Documents/aleeper-config")


if __name__ == '__main__':
    main()
