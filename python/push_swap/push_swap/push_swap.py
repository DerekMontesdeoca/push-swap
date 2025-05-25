from typing import Callable

from .circular_distance import min_distance_to_index
from .direction import Direction


class Stack:
    def __init__(self):
        self.data = []
    
    def rotate(self) -> bool:
        if len(self.data) > 1:
            self.data.insert(0, self.data.pop())
            return True
        return False

    def rrotate(self) -> bool:
        if len(self.data) > 1:
            self.data.append(self.data.pop(0))
            return True
        return False

    def swap(self) -> bool:
        if len(self.data) >= 2:
            temp = self.data[-1]
            self.data[-1] = self.data[-2]
            self.data[-2] = temp
            return True
        return False

    def pop(self) -> int | None:
        return self.data.pop() if self.data else None

    def push(self, elem):
        self.data.append(elem)

    def top(self):
        return self.data[-1]


class PushSwap:
    def __init__(self, elems):
        self.a = Stack()
        self.b = Stack()
        self.a.data = list(reversed(elems))
        self.actions = []
        self.after_action: Callable | None = None

    def print(self):
        print()
        max_range = max(len(self.a.data), len(self.b.data))
        for i in range(max_range):
            index = len(self.a.data) - i - 1
            if index >= 0:
                print(f'|{self.a.data[index]:^12}|', end='')
            else:
                print(f'|{'':^12}|', end='')
            index = len(self.b.data) - i - 1
            if index >= 0:
                print(f'   |{self.b.data[index]:^12}|')
            else:
                print(f'   |{'':^12}|')
        print()

    def append_action(self, action: str):
        self.actions.append(action)
        if self.after_action is not None:
            self.after_action()

    def sa(self):
        if self.a.swap():
            self.append_action('sa')

    def sb(self):
        if self.b.swap():
            self.append_action('sb')

    def ss(self):
        result1 = self.a.swap()
        result2 = self.b.swap()
        if  result1 or result2:
            self.append_action('ss')

    def pa(self):
        elem = self.b.pop()
        if elem is not None:
            self.a.push(elem)
            self.append_action('pa')

    def pb(self):
        elem = self.a.pop()
        if elem is not None:
            self.b.push(elem)
            self.append_action('pb')

    def ra(self):
        if self.a.rotate():
            self.append_action('ra')

    def rb(self):
        if self.b.rotate():
            self.append_action('rb')

    def rr(self):
        result1 = self.a.rotate()
        result2 = self.b.rotate()
        if  result1 or result2:
            self.append_action('rr')

    def rra(self):
        if self.a.rrotate():
            self.append_action('rra')

    def rrb(self):
        if self.b.rrotate():
            self.append_action('rrb')

    def rrr(self):
        result1 = self.a.rrotate()
        result2 = self.b.rrotate()
        if  result1 or result2:
            self.append_action('rrr')

    def top_a_index(self, index: int):
        vector = min_distance_to_index(index, len(self.a.data))
        match vector.direction:
            case Direction.UP:
                for _ in range(vector.magnitude):
                    self.ra()
            case Direction.DOWN:
                for _ in range(vector.magnitude):
                    self.rra()

    def top_a_elem(self, elem: int):
        index = self.a.data.index(elem)
        self.top_a_index(index)

