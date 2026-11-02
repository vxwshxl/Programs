#1. Find the product of two matrices and store it into a file.

def read_matrix(name):
    rows = int(input(f"Enter number of rows for matrix {name}: "))
    cols = int(input(f"Enter number of columns for matrix {name}: "))
    print(f"Enter the {rows}x{cols} elements of matrix {name}, row by row (space separated):")
    matrix = []
    for i in range(rows):
        while True:
            row = list(map(int, input(f"Row {i + 1}: ").split()))
            if len(row) != cols:
                print(f"Expected {cols} values, got {len(row)}. Try again.")
                continue
            matrix.append(row)
            break
    return matrix


def multiply_matrices(a, b):
    rows_a, cols_a = len(a), len(a[0])
    rows_b, cols_b = len(b), len(b[0])

    if cols_a != rows_b:
        raise ValueError(
            f"Cannot multiply {rows_a}x{cols_a} matrix by {rows_b}x{cols_b} matrix: "
            "number of columns in first matrix must equal number of rows in second."
        )

    result = [[0] * cols_b for _ in range(rows_a)]
    for i in range(rows_a):
        for j in range(cols_b):
            result[i][j] = sum(a[i][k] * b[k][j] for k in range(cols_a))
    return result


def format_matrix(matrix):
    return "\n".join(" ".join(str(val) for val in row) for row in matrix)


def main():
    print("Matrix A:")
    matrix_a = read_matrix("A")
    print("\nMatrix B:")
    matrix_b = read_matrix("B")

    product = multiply_matrices(matrix_a, matrix_b)

    output_file = "matrix_product.txt"
    with open(output_file, "w") as f:
        f.write("Matrix A:\n")
        f.write(format_matrix(matrix_a) + "\n\n")
        f.write("Matrix B:\n")
        f.write(format_matrix(matrix_b) + "\n\n")
        f.write("Product (A x B):\n")
        f.write(format_matrix(product) + "\n")

    print(f"\nProduct matrix:\n{format_matrix(product)}")
    print(f"\nResult written to {output_file}")


if __name__ == "__main__":
    main()
