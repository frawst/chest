"""
Given input list of numbers
Output all groups of 3 of these that will sum to 0
"""
from time import time
import csv
import pickle


class Summer:

    def __init__(self):
        self.numbers = []
        self.all_sets = []
        self.zero_sets = []
        self.expected = []

        self.generate_count = 100
        self.number_count = 0

        self.start_time = time()
        self.time_to_run = 0
        self.method_used = ''
        self.test_log_f = ''
        self.test_log_s = ''

    # Generate numbers from -q to q
    def generate_inputs(self, q):
        """
        Generate some list of numbers between -q and q

        Used to create numerical list for sorting and testing

        :param q: quantity to produce in either direction
        :return: none
        """
        self.numbers = []
        for i in range(0 - q, q + 1):
            if i == 0:
                pass
            else:
                self.numbers.append(i)
        self.number_count = len(self.numbers)

    # Log numbers ran count, time to compute, and method used
    def output_logs(self, file='log.csv'):
        with open(file, 'a', newline='') as csvfile:
            logger = csv.writer(csvfile, delimiter=',',
                                quotechar='|', quoting=csv.QUOTE_MINIMAL)
            logger.writerow([self.number_count, self.time_to_run, self.method_used,
                             self.test_log_s, self.test_log_f])

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

    def is_zero_set(self, a, b, c):
        if a + b + c == 0 and not self.is_duplicate_set(a, b, c):
            return True
        else:
            return False

    def test_outputs(self):
        goal = len(self.expected)
        count = 0
        fail = 0
        counted = []
        fails = []
        # print('Input: {}'.format(self.numbers))
        # print('Expected: {}'.format(self.expected))
        for i in self.zero_sets:
            a = i[0]
            b = i[1]
            c = i[2]
            # print(a, b, c)
            # print('Expected: {}'.format(expected))
            if ((a, b, c) in self.expected and not (a, b, c) in counted or
                    (a, c, b) in self.expected and not (a, c, b) in counted or
                    (b, a, c) in self.expected and not (b, a, c) in counted or
                    (b, c, a) in self.expected and not (b, c, a) in counted or
                    (c, a, b) in self.expected and not (c, a, b) in counted or
                    (c, b, a) in self.expected and not (c, b, a) in counted):
                count += 1
                counted.append(i)
            else:
                fail += 1
                fails.append(i)
        self.test_log_s = 'Expected: {}  Got: {}  Fails: {}'.format(goal, count, fail)
        self.test_log_f = 'Fails: {}'.format(fails)

    # Confirmed Functional -- Use to Build Test Sets for Larger Tests
    def brute_list_test(self):
        self.zero_sets = []
        self.method_used = 'brute_list_test'
        self.start_time = time()
        a_mark = 0
        start = time()
        for i in self.numbers:
            a_mark += 1
            b_mark = a_mark
            for j in self.numbers[a_mark:len(self.numbers)]:
                b_mark += 1
                for k in self.numbers[b_mark:len(self.numbers)]:
                    if self.is_zero_set(i, j, k):
                        self.zero_sets.append((i, j, k))

        end = time()
        self.time_to_run = end - start

    # Instead of testing raw numbers, build a list of numeric tuples and
    # test that list for all-positive and all-negative sets
    def numbers_to_tuple_sets(self):
        self.start_time = time()
        self.all_sets = []
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
        self.zero_sets = []
        self.method_used = 'test_by_tuples'
        self.numbers_to_tuple_sets()
        for i in self.all_sets:
            if (i[0] + i[1] + i[2]) == 0:
                self.zero_sets.append(i)

        self.time_to_run = time() - self.start_time
        print('Done in {}'.format(self.time_to_run))

    def test_moving_towards_center(self):
        self.zero_sets = []
        self.method_used = 'moving_towards_center'
        pass

    def build_test_data(self, quantity):
        self.generate_inputs(quantity)
        self.brute_list_test()
        pickle.dump(self.zero_sets, open('data.p', 'wb'))

    def apply_data_to_self(self):
        self.expected = pickle.load(open('data.p', 'rb'))


def multiple_tests(summer, quantity, nrange=100, test='brute_list_test'):
    ran = 0
    while ran < quantity:
        fttime = time()
        if test == 'brute_list_test':
            summer.generate_inputs(nrange)
            summer.brute_list_test()
            summer.test_outputs()
            summer.output_logs('log.csv')
            ran += 1
            print('Test + Error Check Time: {}'.format(time() - fttime))
        elif test == 'test_by_tuples':
            summer.generate_inputs(nrange)
            summer.test_by_tuples()
            summer.test_outputs()
            summer.output_logs('log.csv')
            ran += 1
            print('Test + Error Check Time: {}'.format(time() - fttime))
        else:
            ran += 1


def mast():
    s = Summer()

    # s.build_test_data(100)
    s.apply_data_to_self()
    multiple_tests(s, 10, test='brute_list_test')

    # print(s.expected)
    # print(type(s.expected))
    # multiple_tests(s, 10, test='test_by_tuples')
    # print(s.time_to_run)

if __name__ == '__main__':
    mast()
