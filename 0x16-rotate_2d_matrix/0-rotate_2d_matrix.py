#!/usr/bin/python3
"""rotate_2d_matrix module"""


def rotate_2d_matrix(matrix):
    """Rotate 2-D matrix 90 degrees clockwise

    Args:
        matrix: 2-D matrix to rotate
    """
    if not matrix or len(matrix) == 0:
        return
    size = len(matrix)
    for i in range(size // 2):
        for j in range(i, size - 1 - i):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[size - 1 - j][i]
            matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j]
            matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i]
            matrix[j][size - 1 - i] = tmp
