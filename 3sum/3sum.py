"""
Given input list of numbers
Output all groups of 3 of these that will sum to 0
"""
from time import time
import csv


class Summer:

    def __init__(self):
        self.numbers = []
        self.all_sets = []
        self.zero_sets = []
        self.generate_count = 100
        self.count = 0
        self.generate_inputs(self.generate_count)
        self.start_time = time()
        self.time_to_run = 0

    def generate_inputs(self, q):
        for i in range(0 - q, q + 1):
            if i == 0:
                pass
            else:
                self.numbers.append(i)
        self.count = len(self.numbers)

    def output_logs(self, file='log.csv'):
        with open(file, 'a', newline='') as csvfile:
            logger = csv.writer(csvfile, delimiter=',',
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
            logger.writerow([self.count, self.time_to_run])

    def is_duplicate_set(self, a, b, c):
        if (a, b, c) in self.zero_sets:
            return True
        elif (a, c, b) in self.zero_sets:
            return True
        elif (b, a, c) in self.zero_sets:
            return True
        elif (b, c, a) in self.zero_sets:
            return True
        elif (c, a, b) in self.zero_sets:
            return True
        elif (c, b, a) in self.zero_sets:
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
        for i in self.zero_sets:
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

    def list_test(self):
        a_mark = 0
        start = time()
        for i in self.numbers:
            a_mark += 1
            b_mark = a_mark
            for j in self.numbers[a_mark:len(self.numbers)]:
                b_mark += 1
                for k in self.numbers[b_mark:len(self.numbers)]:
                    if self.check_set(i, j, k):
                        self.zero_sets.append((i, j, k))

        end = time()
        self.time_to_run = end - start

    # Instead of testing raw numbers, build a list of numeric tuples and
    # test that list for all-positive and all-negative sets
    def build_test_list(self):
        a_m = 0
        for i in self.numbers:
            a_m += 1
            b_m = a_m
            for j in (self.numbers[a_m:len(self.numbers)]):
                b_m += 1
                for k in (self.numbers[b_m:len(self.numbers)]):
                    if (i > 0) and (j > 0) and (k > 0):
                        pass
                    elif (i < 0) and (j < 0) and (k < 0):
                        pass
                    else:
                        self.all_sets.append((i, j, k))

    def test_by_tuples(self):
        for i in self.all_sets:
            if (i[0] + i[1] + i[2]) == 0:
                self.zero_sets.append(i)

        self.time_to_run = time() - self.start_time
        print('Done in {}'.format(self.time_to_run))


def mast():
    s = Summer()
    # s.list_test()
    s.generate_count = 100
    s.build_test_list()
    s.test_by_tuples()
    s.output_logs()
    # print(s.sets)
    # s.test_outputs(expected_outputs)
    print(s.time_to_run)

if __name__ == '__main__':
    mast()
