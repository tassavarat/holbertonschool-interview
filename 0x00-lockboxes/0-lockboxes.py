#!/usr/bin/python3


def canUnlockAll(boxes):
    """Checks if all boxes can be opened

    Args:
        boxes: list of lists containing boxes and their keys

    Returns:
        True if all boxes can be opened, otherwise False
    """
    bl = len(boxes)

    if bl == 0:
        return True
    u = [False] * bl
    u[0] = True
    s = [0]

    while s:
        for k in boxes[s.pop()]:
            if k > 0 and k < bl and not u[k]:
                u[k] = True
                s.append(k)

    return all(u)
