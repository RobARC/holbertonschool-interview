#!/usr/bin/python3
""" Task: Change comes from within
Given a pile of coins of different values,
determine the fewest number of coins needed to
meet a given amount total """


def makeChange(coins, total):
    """ Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total.
    Return: fewest number of coins needed to meet total """

    if total <= 0:
        return 0

    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        count += total // coin
        total = total % coin
    if total:
        return -1
    return count
