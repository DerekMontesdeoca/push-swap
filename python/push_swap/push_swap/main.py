import curses
import random

from .push_swap import PushSwap
from .algo import split_insert_sort

def main():
    # ls = list(range(50))
    # random.shuffle(ls)
    # ps = PushSwap(ls)
    # def report():
    #     print(ps.actions[-1])
    #     ps.print()
    # ps.after_action = report
    # ps.print()
    # split_insert_sort(ps)
    # ps.print()
    # print(len(ps.actions))

    ls = list(range(100))
    for _ in range(100):
        random.shuffle(ls)
        ps = PushSwap(ls)
        split_insert_sort(ps)
        ps.print()
        print(len(ps.actions))
        if len(ps.actions) >= 700:
            print('MASSIVE ERROR')
            return
    
if __name__ == '__main__':
    main()
