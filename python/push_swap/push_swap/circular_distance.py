from .direction import Direction
from dataclasses import dataclass


@dataclass
class Vector:
    direction: Direction
    magnitude: int


def min_distance_to_index(index: int, length: int) -> Vector:
    up, down = both_distances_to_index(index, length)
    if up <= down:
        return Vector(direction=Direction.UP, magnitude=up)
    else:
        return Vector(direction=Direction.DOWN, magnitude=down)


def both_distances_to_elem(elem: int, lst: list[int]):
    index = lst.index(elem)
    return both_distances_to_index(index, len(lst))


def distance_in_direction(direction, index, length):
    if length < 0:
        raise ValueError
    elif length <= 1:
        return 0

    match direction:
        case Direction.DOWN:
            distance = index + 1
        case Direction.UP:
            distance = length - 1 - index
        case _:
            raise ValueError
    return distance


def both_distances_to_index(index: int, length: int):
    return (distance_in_direction(Direction.UP, index, length),
            (distance_in_direction(Direction.DOWN, index, length)))


