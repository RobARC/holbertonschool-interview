#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics
"""

import sys


def print_log_parser(total_size, dict_counter):
    print("File size: {}".format(total_size))
    for key, value in sorted(dict_counter.items()):
        if value != 0:
            print("{}: {:d}".format(key, value))


def main():
    """ Main function """
    total_size = 0
    counter = 0
    codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    dict_counter = {'200': 0, '301': 0,
                    '400': 0, '401': 0,
                    '403': 0, '404': 0,
                    '405': 0, '500': 0}

    for line in sys.stdin:
        if counter != 0 and counter % 10 == 0:
            print_log_parser(total_size, dict_counter)

        line_list = line.split(" ")
        if len(line_list) > 2:
            code = line_list[-2]
            size = line_list[-1]
            if code in codes:
                dict_counter[code] += 1
            try:
                total_size += int(size)
            except Exception:
                pass
            counter += 1
        if counter >= 10:
            print_log_parser(total_size, dict_counter)
            counter = 0
    print_log_parser(total_size, dict_counter)


if __name__ == "__main__":
    main()
