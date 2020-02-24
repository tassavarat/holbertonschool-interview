#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

print("boxes = [[1], [2], [3], [4], []]")
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes), "\n")

print("boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]")
boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes), "\n")

print("boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]")
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes), "\n")

print("boxes = []")
boxes = []
print(canUnlockAll(boxes), "\n")

print("boxes = [[]]")
boxes = [[]]
print(canUnlockAll(boxes), "\n")

print("boxes = [[1], [5], [2]]")
boxes = [[1], [5], [2]]
print(canUnlockAll(boxes), "\n")

print("boxes = [[1], [2], [5]]")
boxes = [[1], [2], [5]]
print(canUnlockAll(boxes), "\n")
