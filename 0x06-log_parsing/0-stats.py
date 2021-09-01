#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics
"""


def print_log_paser(total_size, code_counter):
    print("File size: {}".format(total_size))
    for code in code_counter:
        if code_counter[code] > 0:
            print("{}: {:d}".format(code, code_counter[code]))


if __name__ == '__main__':
    import sys
    from collections import OrderedDict
    from datetime import datetime

    """
        Reads stdin line by line and computes metrics
        Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
        <status code> <file size>
    """

    total_size = 0
    line_counter = 0
    code_counter = OrderedDict.fromkeys([200, 301, 400, 401,
                                         403, 404, 405, 500], 0)

    try:
        for line in sys.stdin:
            line_counter += 1
            a = line.split('-', 1)
            if len(a) != 2:
                continue

            # checking timestamp
            b = a[1].split(']')
            timecode = b[0].lstrip(' [')
            try:
                datetime.strptime(timecode,
                                  '%Y-%m-%d %H:%M:%S.%f')
            except Exception:
                sys.stderr.write("{}: {}: invalid timecode\n".
                                 format(sys.argv[0], line_counter))
                pass

            # checking URL
            c = b[1].split('"')
            c = c[1:]
            if c[0] != 'GET /projects/260 HTTP/1.1':
                sys.stderr.write("{}: {}: unexpected HTTP request\n".
                                 format(sys.argv[0], line_counter))

            d = c[1].lstrip(' ')
            d = d.rstrip('\n')
            d = d.split(' ')

            if d[0].isdecimal():
                code = int(d[0])
                code_counter[code] += 1

            if d[1].isdecimal():
                total_size += int(d[1])

            if line_counter == 10:
                print_log_paser(total_size, code_counter)
                line_counter = 0

        print_log_paser(total_size, code_counter)

    except (KeyboardInterrupt):
            print_log_paser(total_size, code_counter)
            raise
