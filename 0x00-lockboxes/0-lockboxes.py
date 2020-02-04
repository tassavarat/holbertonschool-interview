#!/usr/bin/python3


def canUnlockAll(boxes):
    s = set()
    a = [0]

    if isinstance(boxes, list):
        for i in range(len(boxes)):
            if not isinstance(boxes[a[i]], list):
                return False
            a.extend(boxes[a[i]])
        s.update(a)
        for n in s:
            if n < 0 or n > len(boxes) - 1:
                return False
        if len(s) == len(boxes):
            return True

    return False
