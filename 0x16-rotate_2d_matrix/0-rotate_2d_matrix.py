#!/usr/bin/python3


def rotate_2d_matrix(matrix):
    """Rotate 2-D matrix 90 degrees clockwise

    Args:
        matrix: 2-D matrix to rotate
    """
    if not matrix or len(matrix) == 0:
        return
    cols = len(matrix[0])
    tmp = matrix[0][:]
    for r in range(len(matrix)):
        for c in range(cols - 1):
            matrix[r][c] = matrix[cols - c - 1][r]
        matrix[r][cols - 1] = tmp[r]
