#!/usr/bin/python3


def validUTF8(data):
    """Determines if given data represents valid UTF-8 encoding

    Args:
        data: list of integers

    Returns:
        True if valid UTF-8 encoding, otherwise False
    """
    bytes_on = 0
    for n in data:
        mask = 1 << 7
        if not bytes_on:
            while n & mask:
                bytes_on += 1
                mask >>= 1
            if not bytes_on:
                continue
            if bytes_on > 4:
                return False
        elif n >> 6 != 2:
            return False
        bytes_on -= 1
    return bytes_on == 0
