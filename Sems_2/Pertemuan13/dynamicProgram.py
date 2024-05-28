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

dimensions = [1, 2, 3, 4, 3]
print(matrixChainOrder(dimensions))  # Output: 30