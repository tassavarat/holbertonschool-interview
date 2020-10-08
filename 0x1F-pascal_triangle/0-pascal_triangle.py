#!/usr/bin/python3
"""0-pascal_triangle module"""


def pascal_triangle(n):
    """Create Pascal's triangle of n height

    Args:
        n: height of triangle

    Returns: created triangle
    """
    if n <= 0:
        return []

    triangle = []
    for i in range(n):
        sub = [1] * (i + 1)
        for j in range(i - 1):
            sub[j + 1] = triangle[i - 1][j] + triangle[i - 1][j + 1]
        triangle.append(sub)
    return triangle
