#3. Create a matrix of 2D array and find row sum and column sum of the matrix.

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]

print("Matrix:")
for row in matrix:
    print(row)

print("\nRow sums:")
for i, row in enumerate(matrix):
    print(f"  Row {i}: {sum(row)}")

num_cols = len(matrix[0])
print("\nColumn sums:")
for j in range(num_cols):
    col_sum = sum(row[j] for row in matrix)
    print(f"  Column {j}: {col_sum}")
