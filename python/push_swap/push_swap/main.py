import curses
import random
from curses import wrapper
import time

from .push_swap import PushSwap
from .algo import split_insert_sort

def print_line_up(s, height, y, x):
    maxy, maxx = s.getmaxyx()
    full_height = height // 8
    cp = curses.color_pair(1) if x % 2 == 0 else curses.color_pair(2)
    for j in range(full_height):
        cur_y = y - j
        if 0 <= cur_y < maxy - 1 and 0 <= x < maxx-1:
            s.addch(cur_y, x, "█", cp)
    cur_y = y - full_height
    c = " "
    match height % 8:
        case 0:
            c = " "
        case 1:
            c = "\u2581"
        case 2:
            c = "\u2582"
        case 3:
            c = "\u2583"
        case 4:
            c = "\u2584"
        case 5:
            c = "\u2585"
        case 6:
            c = "\u2586"
        case 7:
            c = "\u2587"
    if 0 <= cur_y < maxy - 1 and 0 <= x <= maxx - 1:
        s.addch(cur_y, x, c, cp)


def print_curses(s, ps):
    maxy, maxx = s.getmaxyx()
    midx = maxx // 2

    s.clear()

    for y in range(maxy):
        s.addch(y, midx, "|", curses.color_pair(3))

    for i in range(len(ps.a.data)):
        print_line_up(s, ps.a.data[-i - 1] + 1, maxy - 2, midx - 1 - i)
    for i in range(len(ps.b.data)):
        print_line_up(s, ps.b.data[i] + 1, maxy - 2, midx + 1 + i)


def main(stdscr):
    curses.start_color()
    curses.init_pair(1, curses.COLOR_WHITE, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_CYAN, curses.COLOR_BLACK)
    curses.init_pair(3, curses.COLOR_RED, curses.COLOR_BLACK)

    ls = list(range(100))
    random.shuffle(ls)
    ps = PushSwap(ls)

    print_curses(stdscr, ps)
    stdscr.refresh()

    def print_step():
        time.sleep(0.02)
        print_curses(stdscr, ps)
        stdscr.refresh()

    ps.after_action = print_step

    split_insert_sort(ps)
    print_curses(stdscr, ps)
    stdscr.refresh()

    stdscr.getkey()

    if len(ps.actions) >= 700:
        return

    
wrapper(main)
