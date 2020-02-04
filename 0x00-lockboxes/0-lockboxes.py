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
            for k in b:
                if not isinstance(k, int) or k < 0 or k > len(boxes) - 1:
                    return False

        for i in range(len(boxes)):
            a.extend(boxes[a[i]])
        s.update(a)
        if len(s) == len(boxes):
            return True

    return False
