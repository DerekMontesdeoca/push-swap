import pytest
import random
import subprocess
from subprocess import run, Popen

PUSH_SWAP = '../src/push_swap'

def test_simple():
    result = run([PUSH_SWAP, '2', '1', '3'], text=True, capture_output=True);
    assert result.returncode == 0
    assert result.stdout.count("\n") == 4


def test_100_nums_is_lt_700():
    for _ in range(50):
        lst = [str(random.randint(-(2**31), 2**31-1)) for _ in range(100)]
        lst.insert(0, PUSH_SWAP)
        result = run(lst, text=True, capture_output=True)
        assert(result.returncode == 0)
        assert(result.stderr == "")
        assert(result.stdout.count("\n") <= 700)


def test_500_nums_is_lt_5500():
    for _ in range(50):
        lst = [str(random.randint(-(2**31), 2**31-1)) for _ in range(500)]
        lst.insert(0, PUSH_SWAP)
        result = run(lst, text=True, capture_output=True)
        assert(result.returncode == 0)
        assert(result.stderr == "")
        assert(result.stdout.count("\n") <= 5500)


def test_number_out_of_range():
    result = run([PUSH_SWAP, str(2**31)], capture_output=True)
    assert(result.returncode == 1)
    assert(result.stderr == b"Error\n")


def test_nan():
    result = run([PUSH_SWAP, "hola"], capture_output=True)
    assert(result.returncode == 1)
    assert(result.stderr == b"Error\n")


def test_no_args():
    result = run([PUSH_SWAP], capture_output=True)
    assert(result.returncode == 0)
    assert(result.stderr == b"")
    assert(result.stdout == b"\n")


def test_reversed_100():
    lst = [str(i) for i in range(99, -1, -1)]
    lst.insert(0, PUSH_SWAP)
    result = run(lst, capture_output=True, text=True)
    print(result.stdout)
    assert(result.returncode == 0)
    assert(result.stdout.count('\n') < 700)
    assert(result.stderr == "");


def test_reversed_500():
    lst = [str(i) for i in range(499, -1, -1)]
    lst.insert(0, PUSH_SWAP)
    result = run(lst, capture_output=True, text=True)
    print(result.stdout)
    assert(result.returncode == 0)
    assert(result.stdout.count('\n') < 5500)
    assert(result.stderr == "");


def test_against_checker():
    for _ in range(100):
        lst = [
            str(random.randint(-(2**31), 2**31-1)) 
            for _ in range(random.randint(1,500))
        ]
        print('start')
        print(len(lst))
        for v in lst:
            print(v)
        lst.insert(0, PUSH_SWAP)
        r1 = run(lst, capture_output=True)
        assert(r1.returncode == 0)
        assert(r1.stderr == b"")
        print(r1.stdout.decode())
        lst[0] = "./checker_42"
        r2 = run(
            lst,
            capture_output=True,
            input=r1.stdout
        )
        assert(r2.returncode == 0)
        assert(r2.stdout == b"OK\n")


