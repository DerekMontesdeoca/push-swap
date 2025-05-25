
def lis(lis_check_numbers):
    tails = []
    indices = []
    result = []

    for i, n in enumerate(lis_check_numbers):
        found = None
        for j, t in enumerate(tails):
            if n < lis_check_numbers[t]:
                found = j
                break
        else:
            found = len(tails)

        if found == len(tails):
            tails.append(i)
        else:
            tails[found] = i;

        if found == 0:
            indices.append(-1);
        else:
            indices.append(tails[found - 1])

    cur_index = -1
    if len(tails) > 0:
        cur_index = tails[-1]
    while (cur_index != -1):
        result.append(cur_index)
        cur_index = indices[cur_index]

    result.reverse()
    return result


def circular_lis_indices(numbers):
    frame = numbers * 2
    max_lis = []
    cur_lis = []
    for i, _ in enumerate(numbers):
        cur_lis = lis(frame[i:i+len(numbers)])
        if len(cur_lis) > len(max_lis):
            max_lis = list(map(lambda x: (x + i) % len(numbers), cur_lis))
    return max_lis


def circular_lis(numbers):
    indices = circular_lis_indices(numbers)
    return [numbers[i] for i in indices]
