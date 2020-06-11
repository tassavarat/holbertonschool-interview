#!/usr/bin/python3
"""trapping rain water module"""

def rain(walls):
    """Compute how much water can be trapped

    Args:
        walls: list of height values

    Returns:
        amount of water able to be trapped
    """
    l = water = lmax = rmax = 0
    r = len(walls) - 1

    while l < r:
        if walls[l] < walls[r]:
            if walls[l] < lmax:
                water += lmax - walls[l]
            else:
                lmax = walls[l]
            l += 1
        else:
            if walls[r] < rmax:
                water += rmax - walls[r]
            else:
                rmax = walls[r]
            r -= 1
    return water
