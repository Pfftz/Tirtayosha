def matrixChainOrder(p):
    n = len(p)
    m = [[0 for x in range(n)] for x in range(n)]
    for L in range(2, n):
        for i in range(1, n - L + 1):
            j = i + L - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
    return m[1][n - 1]

# Example 1
dimensions1 = [1, 2, 3, 4, 3]
print('Minimum number of scalar multiplications for dimensions1:', matrixChainOrder(dimensions1))

# Example 2
dimensions2 = [5, 10, 3, 12, 5, 50, 6]
print('Minimum number of scalar multiplications for dimensions2:', matrixChainOrder(dimensions2))

# Example 3
dimensions3 = [4, 2, 3, 1, 3]
print('Minimum number of scalar multiplications for dimensions3:', matrixChainOrder(dimensions3))