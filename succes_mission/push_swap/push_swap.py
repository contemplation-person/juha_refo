from collections import deque
from random import shuffle
from sys import argv

import matplotlib.pyplot as plt


def push_a(stacks):
    stacks[0].appendleft(stacks[1].popleft())
    return "pa"


def push_b(stacks):
    stacks[1].appendleft(stacks[0].popleft())
    return "pb"


def rotate_a(stacks):
    stacks[0].append(stacks[0].popleft())
    return "ra"


def rotate_b(stacks):
    stacks[1].append(stacks[1].popleft())
    return "rb"


def get_stacks(stacks_len):
    stacks = [deque((i, bin(i)[2:]) for i in range(stacks_len)), deque()]
    shuffle(stacks[0])
    return stacks


def get_merge_moves_to_a(stacks, a_len, b_len):
    moves = []

    while a_len > 0 and b_len > 0:
        a_top, b_top = stacks[0][0][0], stacks[1][0][0]
        if a_top < b_top:
            a_len -= 1
        else:
            moves.append(push_a(stacks))
            b_len -= 1
        moves.append(rotate_a(stacks))
    while a_len > 0:
        moves.append(rotate_a(stacks))
        a_len -= 1
    while b_len > 0:
        moves.append(push_a(stacks))
        moves.append(rotate_a(stacks))
        b_len -= 1

    return moves


def get_merge_moves_to_b(stacks, a_len, b_len):
    moves = []

    while a_len > 0 and b_len > 0:
        a_top, b_top = stacks[0][0][0], stacks[1][0][0]
        if a_top < b_top:
            moves.append(push_b(stacks))
            a_len -= 1
        else:
            b_len -= 1
        moves.append(rotate_b(stacks))
    while a_len > 0:
        moves.append(push_b(stacks))
        moves.append(rotate_b(stacks))
        a_len -= 1
    while b_len > 0:
        moves.append(rotate_b(stacks))
        b_len -= 1

    return moves


def get_init_merge_moves(stacks, length):
    moves = []
    for _ in range(length // 2):
        moves.append(push_b(stacks))
    return moves


def merge_sort(stacks):
    answer = []
    length = len(stacks[0])
    answer.extend(get_init_merge_moves(stacks, length))

    check = 2
    while length > check:
        max_merge_arr_len = check >> 1
        for i in range(length // check):
            if i % 2 == 0:
                answer.extend(
                    get_merge_moves_to_a(stacks, max_merge_arr_len, max_merge_arr_len)
                )
            else:
                answer.extend(
                    get_merge_moves_to_b(stacks, max_merge_arr_len, max_merge_arr_len)
                )
        mod_length = length % check
        if mod_length > 0:
            if mod_length - max_merge_arr_len > 0:
                len_a = max_merge_arr_len
                len_b = mod_length - max_merge_arr_len
            else:
                len_a = mod_length
                len_b = 0
            if (i + 1) % 2 == 0:
                answer.extend(get_merge_moves_to_a(stacks, len_a, len_b))
            else:
                answer.extend(get_merge_moves_to_b(stacks, len_a, len_b))

        check <<= 1

    answer.extend(get_merge_moves_to_a(stacks, len(stacks[0]), len(stacks[1])))

    reduced_answer = []
    for c in answer:
        if reduced_answer and len({"ra", "rb"} - {c, reduced_answer[-1]}) == 0:
            reduced_answer[-1] = "rr"
        else:
            reduced_answer.append(c)

    return reduced_answer


def get_radix_moves(is_zero, stack_id, stacks):
    moves = []
    if is_zero:
        if stack_id == 1:
            moves.append(push_a(stacks))
        moves.append(rotate_a(stacks))
    else:
        if stack_id == 0:
            moves.append(push_b(stacks))
        moves.append(rotate_b(stacks))
    return moves


def radix_sort(stacks):
    answer = []
    max_bin_length = len(bin(len(stacks[0]) - 1)) - 2
    for pos in range(-1, -max_bin_length - 1, -1):
        stacks_len = [len(stack) for stack in stacks]
        for stack_id, stack in enumerate(stacks):
            for _ in range(stacks_len[stack_id]):
                top = stack[0][1]
                is_zero = top[pos] == "0" if len(top) >= abs(pos) else True
                answer.extend(get_radix_moves(is_zero, stack_id, stacks))
    for _ in range(len(stacks[1])):
        answer.append(push_a(stacks))
        answer.append(rotate_a(stacks))
    reduced_answer = []
    for c in answer:
        if reduced_answer and len({"ra", "rb"} - {c, reduced_answer[-1]}) == 0:
            reduced_answer[-1] = "rr"
        else:
            reduced_answer.append(c)

    return reduced_answer


def int_to_ternary(num, dp={0: "0"}):
    if num in dp:
        return dp[num]
    ternary = deque()
    cur_num = num
    while cur_num > 0:
        ternary.appendleft(str(cur_num % 3))
        cur_num //= 3
    dp[num] = "".join(ternary)
    return dp[num]


# def get_radix_3_moves(radix, stack_id, stacks):
#     pass


# def radix_3_sort(stacks):
#     answer = []
#     max_bin_length = len(int_to_ternary(len(stacks[0]) - 1))
#     for pos in range(-1, -max_bin_length - 1, -1):
#         stacks_len = [len(stack) for stack in stacks]
#         for stack_id, stack in enumerate(stacks):
#             for _ in range(stacks_len[stack_id]):
#                 top = stack[0][1]
#                 radix = top[pos] if len(top) >= abs(pos) else "0"
#                 answer.extend(get_radix_3_moves(radix, stack_id, stacks))
#     for _ in range(len(stacks[1])):
#         answer.append(push_a(stacks))
#         answer.append(rotate_a(stacks))
#     return answer


if __name__ == "__main__":
    start, end = int(argv[1]), int(argv[2]) + 1
    ys = []
    for stacks_len in range(start, end):
        if stacks_len <= 0:
            continue
        stacks = get_stacks(stacks_len)
        print(
            f"{stacks_len} -- MERGE, RADIX ==",
            len(merge_sort(stacks)),
            len(radix_sort(stacks)),
        )
