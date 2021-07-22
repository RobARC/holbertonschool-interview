#!/usr/bin/python3
""" method lockboxes """


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened."""

    if not boxes or len(boxes) is 0:
        return False
    
    if len(boxes) == 1:
        if type(boxes[0]) != list:
            return False

    MyKey = [0]

    for num in MyKey:
        for key in boxes[num]:
            if key not in MyKey and key != num \
               and key < len(boxes) and key != 0:
                MyKey.append(key)

    if len(MyKey) == len(boxes):
        return True
    return False
