from dataclasses import dataclass

from .push_swap import PushSwap
from .lis import circular_lis
from .circular_distance import both_distances_to_index


def sorted_position(elem: int, circular_list: list[int]) -> int:
    if len(circular_list) < 2:
        return 0
    minimum = 0
    if circular_list[-1] >= elem >= circular_list[0]:
        return len(circular_list) - 1
    for i in range(len(circular_list) - 1):
        if circular_list[i] < circular_list[minimum]:
            minimum = i
        if circular_list[i] >= elem >= circular_list[i + 1]:
            return i
    if circular_list[-1] < circular_list[minimum]:
        minimum = len(circular_list) - 1
    return minimum


@dataclass
class Movements:
    ra: int = 0
    rra: int = 0
    rb: int = 0
    rrb: int = 0
    rr: int = 0
    rrr: int = 0
    amount: int = 0

    def execute(self, push_swap: PushSwap):
        ops = [
            (self.ra, push_swap.ra), 
            (self.rra, push_swap.rra), 
            (self.rb, push_swap.rb), 
            (self.rrb, push_swap.rrb), 
            (self.rr, push_swap.rr), 
            (self.rrr, push_swap.rrr), 
        ]
        for n, op in ops:
            for _ in range(n):
                op()


def min_insert_movements(index_a, len_a, index_b, len_b) -> Movements:
    dist_a_up, dist_a_down = both_distances_to_index(index_a, len_a)
    dist_b_up, dist_b_down = both_distances_to_index(index_b, len_b)
    
    dist_down = max(dist_a_down, dist_b_down)
    dist_up = max(dist_a_up, dist_b_up)
    dist_a_up_diff = dist_a_up + dist_b_down
    dist_a_down_diff = dist_a_down + dist_b_up

    movements = Movements()

    dists = [dist_a_up_diff, dist_a_down_diff, dist_up, dist_down]
    min_index = min(enumerate(dists), key=lambda x: x[1])[0]
    movements.amount = dists[min_index]
    match min_index:
        case 2:
            movements.rr = min(dist_a_up, dist_b_up)
            rest = dist_up - movements.rr
            if dist_a_up >= dist_b_up:
                movements.rb = rest
            else:
                movements.ra = rest
        case 3:
            movements.rrr = min(dist_a_down, dist_b_down)
            rest = dist_down - movements.rrr
            if dist_a_down >= dist_b_down:
                movements.rrb = rest
            else:
                movements.rra = rest
        case 0:
            movements.rb = dist_a_up
            movements.rra = dist_b_down
        case 1:
            movements.rrb = dist_a_down
            movements.ra = dist_b_up

    return movements


def insert_sort_b_to_a(push_swap: PushSwap):
    while (push_swap.b.data):
        min_movements = None
        for i, elem in enumerate(push_swap.b.data):
            pos_a = sorted_position(elem, push_swap.a.data)
            movements = min_insert_movements(i, len(push_swap.b.data), pos_a, len(push_swap.a.data))

            # if min_movements is None or movements.amount <= min_movements.amount:
            # # if min_movements is None or movements.amount <= min_movements.amount:
            if min_movements is None or movements.amount < min_movements.amount \
                    or (movements.amount == min_movements.amount \
                    and (movements.ra + movements.rra + movements.rr + movements.rrr) \
                    < (min_movements.ra + min_movements.rra + min_movements.rr + min_movements.rrr)):
                min_movements = movements

        if min_movements is not None:
            min_movements.execute(push_swap)
            push_swap.pa()


def lis_pivot_split(push_swap: PushSwap):
    lis_list = circular_lis(list(reversed(push_swap.a.data)))
    if len(lis_list) == len(push_swap.a.data):
        return

    to_push_b = list(set(push_swap.a.data) - set(lis_list))

    # Sort the elems to push in order of appearance in initial stack a.
    to_push_b.sort(key=push_swap.a.data.index)
    to_push_b.reverse() # Reverse because the stack is an inverted array

    pivot = list(sorted(to_push_b))[len(to_push_b) // 2]
    for elem in to_push_b:
        push_swap.top_a_elem(elem)
        push_swap.pb()
        if push_swap.b.top() < pivot:
            push_swap.rb()


def split_insert_sort(push_swap: PushSwap):
    lis_pivot_split(push_swap)
    insert_sort_b_to_a(push_swap)
    push_swap.top_a_elem(0)

