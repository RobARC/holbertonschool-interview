#!/usr/bin/python3
'''
    Method that calculates the fewest number of operations
'''


def minOperations(n):
    if n <= 1:
        return 0

    num_oper = 0
    x = 2
    while n > 1:
        while n % x == 0:
            num_oper += x
            n = int(n / x)
        x += 1
    return num_oper
