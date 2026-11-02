#5. Create a matrix (2D) with random numbers, then sort each row of that matrix.

import random


def create_random_matrix(rows, cols, low=1, high=100):
    return [[random.randint(low, high) for _ in range(cols)] for _ in range(rows)]


def sort_rows(matrix):
    return [sorted(row) for row in matrix]


def print_matrix(matrix):
    for row in matrix:
        print(row)


def main():
    rows, cols = 4, 5
    matrix = create_random_matrix(rows, cols)

    print("Original matrix:")
    print_matrix(matrix)

    sorted_matrix = sort_rows(matrix)

    print("\nMatrix with each row sorted:")
    print_matrix(sorted_matrix)


if __name__ == "__main__":
    main()
