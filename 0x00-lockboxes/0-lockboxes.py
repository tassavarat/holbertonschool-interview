#!/usr/bin/python3


def canUnlockAll(boxes):
    u = [False] * len(boxes)
    u[0] = True
    s = [0]

    while s:
        for k in boxes[s.pop()]:
            if not u[k]:
                u[k] = True
                s.append(k)

    return all(u)
