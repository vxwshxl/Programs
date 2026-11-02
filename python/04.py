#4. Create a 3D matrix and row & column sums.

def create_3d_matrix(depth, rows, cols):
    matrix = []
    value = 1
    for _ in range(depth):
        layer = []
        for _ in range(rows):
            row = [value + i for i in range(cols)]
            value += cols
            layer.append(row)
        matrix.append(layer)
    return matrix


def print_3d_matrix(matrix):
    for d, layer in enumerate(matrix):
        print(f"Layer {d}:")
        for row in layer:
            print(f"  {row}")


def row_sums(matrix):
    # Sum along each row, per layer
    return [[sum(row) for row in layer] for layer in matrix]


def column_sums(matrix):
    # Sum down each column, per layer
    return [[sum(col) for col in zip(*layer)] for layer in matrix]


def main():
    depth, rows, cols = 2, 3, 4
    matrix = create_3d_matrix(depth, rows, cols)

    print("3D Matrix:")
    print_3d_matrix(matrix)

    r_sums = row_sums(matrix)
    c_sums = column_sums(matrix)

    print("\nRow sums (per layer):")
    for d, sums in enumerate(r_sums):
        print(f"  Layer {d}: {sums}")

    print("\nColumn sums (per layer):")
    for d, sums in enumerate(c_sums):
        print(f"  Layer {d}: {sums}")


if __name__ == "__main__":
    main()
