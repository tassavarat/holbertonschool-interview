#!/usr/bin/python3
def prime(n):
    """Determines whether number is prime

    Args:
        n: number being evaluated

    Returns:
        True if number is prime, otherwise False
    """
    if n <= 3:
        return n > 1
    elif n % 2 == 0 or n % 3 == 0:
        return False

    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def minOperations(n):
    """Calculates minimum copy all and paste operations to reach n characters

    Args:
        n: characters to reach

    Returns:
        minimum needed operations
    """
    sum = 0
    while n != 0 and not prime(n):
        if n % 2 == 0:
            sum += 2
            n //= 2
        elif n % 3 == 0:
            sum += 3
            n //= 3
        else:
            return 0
    return sum + n
