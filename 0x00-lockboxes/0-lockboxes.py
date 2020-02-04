#!/usr/bin/python3


def canUnlockAll(boxes):
    s = set()
    a = [0]

    if isinstance(boxes, list):
        for i in range(len(boxes)):
            a.extend(boxes[a[i]])
        s.update(a)
        if len(s) == len(boxes):
            return True

    return False
