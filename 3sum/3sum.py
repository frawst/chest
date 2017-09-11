"""
Given input list of numbers
Output all groups of 3 of these that will sum to 0

Input Example

You will be given a list of integers, one set per line. Example:

9 -6 -5 9 8 3 -4 8 1 7 -4 9 -9 1 9 -9 9 4 -6 -8

Output Example

Your program should emit triplets of numbers that sum to 0. Example:

-9 1 8
-8 1 7
-5 -4 9
-5 1 4
-4 1 3
-4 -4 8

Challenge Input

4 5 -1 -2 -7 2 -5 -3 -7 -3 1
-1 -6 -3 -7 5 -8 2 -8 1
-5 -1 -4 2 9 -9 -6 -1 -7

Challenge Output

-7 2 5
-5 1 4
-3 -2 5
-3 -1 4
-3 1 2

-7 2 5
-6 1 5
-3 1 2

-5 -4 9
-1 -1 2

"""
from time import time

# test_input = [9, -6, -5, 9, 8, 3, -4, 8, 1, 7, -4, 9, -9, 1, 9, -9, 9, 4, -6, -8]
# expected_outputs = [(-9, 1, 8), (-8, 1, 7), (-5, -4, 9), (-5, 1, 4), (-4, 1, 3), (-4, -4, 8)]

test_input = [4, 5, -1, -2, -7, 2, -5, -3, -7, -3, 1]
expected_outputs = [(-7, 2, 5), (-5, 1, 4), (-3, -2, 5), (-3, -1, 4), (-3, 1, 2)]

# expected_outputs = [(-5, -4, 9), (-1, -1, 2)]

class Summer:

    def __init__(self):
        self.numbers = test_input
        self.sets = []

    def is_duplicate_set(self, a, b, c):
        if (a, b, c) in self.sets:
            return True
        elif (a, c, b) in self.sets:
            return True
        elif (b, a, c) in self.sets:
            return True
        elif (b, c, a) in self.sets:
            return True
        elif (c, a, b) in self.sets:
            return True
        elif (c, b, a) in self.sets:
            return True
        else:
            return False

    def check_set(self, a, b, c):
        if a + b + c == 0 and not self.is_duplicate_set(a, b, c):
            return True
        else:
            return False

    def test_outputs(self, expected):
        goal = len(expected)
        count = 0
        fail = 0
        counted = []
        fails = []
        print('Input: {}'.format(self.numbers))
        print('Expected: {}'.format(expected))
        for i in self.sets:
            a = i[0]
            b = i[1]
            c = i[2]
            # print(a, b, c)
            # print('Expected: {}'.format(expected))
            if ((a, b, c) in expected and not (a, b, c) in counted or
                (a, c, b) in expected and not (a, c, b) in counted or
                (b, a, c) in expected and not (b, a, c) in counted or
                (b, c, a) in expected and not (b, c, a) in counted or
                (c, a, b) in expected and not (c, a, b) in counted or
                (c, b, a) in expected and not (c, b, a) in counted):
                count += 1
            else:
                fail += 1
                fails.append((a, b, c))
        print('Expected: {}  Got: {}  Fails: {}'.format(goal, count, fail))
        print('Fails: {}'.format(fails))


def mast():
    start = time()
    s = Summer()
    a_mark = 0
    for i in s.numbers:
        a_mark += 1
        b_mark = a_mark
        for j in s.numbers[a_mark:len(s.numbers)]:
            b_mark += 1
            for k in s.numbers[b_mark:len(s.numbers)]:
                if s.check_set(i, j, k):
                    s.sets.append((i, j, k))

    complete = time()
    print(s.sets)
    s.test_outputs(expected_outputs)
    print('Time to complete: {} ms'.format(complete - start))

if __name__ == '__main__':
    mast()
