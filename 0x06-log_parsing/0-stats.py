#!/usr/bin/python3
from sys import stdin
from collections import OrderedDict

fs = -1
sc = -2


def printstat():
    print("File size:", file_size)
    for k, v in stat.items():
        print("{}: {}".format(k, v))


def parselog(file_size):
    arr = line.split()
    # print("debug", arr[sc])
    file_size += int(arr[fs])
    if arr[sc] in stat:
        stat[arr[sc]] += 1
        # print(stat.items())
    return file_size


file_size = 0
count = 1
stat = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0, "405": 0,
        "500": 0}
try:
    for line in stdin:
        file_size = parselog(file_size)
        if count % 10 == 0:
            # print("10 lines")
            printstat()
        count += 1
except KeyboardInterrupt:
    printstat()
    raise
