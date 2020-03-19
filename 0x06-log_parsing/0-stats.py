#!/usr/bin/python3
from sys import stdin

fs = -1
sc = -2

if __name__ == "__main__":
    def printstat():
        print("File size:", file_size)
        for k, v in sorted(stat.items()):
            if v:
                print("{}: {}".format(k, v))

    def parselog(file_size):
        arr = line.split()
        try:
            file_size += int(arr[fs])
            if arr[sc] in stat:
                stat[arr[sc]] += 1
        except Exception as e:
            print(e)
        return file_size

    try:
        file_size = 0
        count = 1
        stat = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
                "405": 0, "500": 0}
        for line in stdin:
            file_size = parselog(file_size)
            if count % 10 == 0:
                printstat()
            count += 1
        printstat()
    except KeyboardInterrupt:
        printstat()
        raise
