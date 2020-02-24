#!/usr/bin/python3
def minOperations(n):
    """Calculates minimum copy all and paste operations to reach n characters

    Args:
        n: characters to reach

    Returns:
        minimum needed operations
    """
    sum = 0
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            sum += i
    if n > 1:
        sum += n
    return sum
