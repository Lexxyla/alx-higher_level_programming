#!/usr/bin/python3
def print_sorted_dictionary(a_dictionary):
    for i in sorted(a_dictionary):
        print("{:s}: {}".format(i, a_dictionary[i]))
