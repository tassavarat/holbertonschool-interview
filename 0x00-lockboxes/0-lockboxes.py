#!/usr/bin/python3


def canUnlockAll(boxes):
    s = set()
    a = [0]

    if len(boxes) == 0:
        return True
    if isinstance(boxes, list):
        for b in boxes:
            if not isinstance(b, list):
                return False
            for ki in range(len(b)):
                if not isinstance(b[ki], int):
                    return False
                if b[ki] < 0 or b[ki] > len(boxes) - 1:
                    del b[ki]

        for i in range(len(boxes)):
            a.extend(boxes[a[i]])
        s.update(a)
        if len(s) == len(boxes):
            return True

    return False
