#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics
"""
import sys


total_size = 0
counter = 0
codes = ['200', '301', '400', '401', '403', '404', '405', '500']
dict_counter = {'200': 0, '300': 0,
                '400': 0, '401': 0,
                '403': 0, '404': 0,
                '405': 0, '500': 0}

try:
    for line in sys.stdin:
        line_list = line.split(" ")
        if len(line_list) > 2:
            code = line_list[-2]
            size = line_list[-1]
            if code in codes:
                dict_counter[code] += 1
            total_size += int(size)
            counter += 1

        if counter == 10:
            print("File size: {:s}".format(total_size))
            for key, value in sorted(dict_counter.items()):
                if value != 0:
                    print("{}: {:d}".format(key, value))
            counter = 0

except Exception:
    pass
finally:
    print("File size: {}".format(total_size))
    for key, value in sorted(dict_counter.items()):
        if value != 0:
                    print("{}: {:d}".format(key, value))
