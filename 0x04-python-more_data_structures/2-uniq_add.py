#!/usr/bin/python3
def uniq_add(my_list=[]):
    new = set(my_list)
    res = 0
    for i in new:
        res += i
    return res
