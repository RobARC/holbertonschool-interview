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
        return

    change = 0
    coins.sort(reverse=True)
    for coin in coins:
        temp_change = int(total / coin)
        total -= (temp_change * coin)
        change += temp_change
        if total == 0:
            return change
    if total != 0:
        return -1
