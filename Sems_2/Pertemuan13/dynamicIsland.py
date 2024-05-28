def lcs(X, Y): 
    m = len(X) 
    n = len(Y) 
    dp = [[""] * (n + 1) for _ in range(m + 1)] 
 
    # Mengisi tabel dp dan membangun LCS 
    for i in range(1, m + 1): 
        for j in range(1, n + 1): 
            if X[i-1] == Y[j-1]: 
                dp[i][j] = dp[i-1][j-1] + X[i-1] 
            else: 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1], key=len) 
 
    # Mengembalikan LCS 
    return dp[m][n] 
 
def knapsack(W, weights, values, n):
    # Inisialisasi tabel dp
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]

    # Mengisi tabel dp
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][W]

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


values = [60, 100, 120]
weights = [10, 20, 30]
W = 50
n = len(values)
print('Algoritma knapsack dengan dynamic programming')
print('Maximum value that can be obtained:', knapsack(W, weights, values, n))

dimensions1 = [1, 2, 3, 4, 3]
dimensions2 = [5, 10, 3, 12, 5, 50, 6]
dimensions3 = [4, 2, 3, 1, 3]
print('\nAlgoritma matrix chain multiplication dengan dynamic programming')
print('Minimum number of scalar multiplications for dimensions1:', matrixChainOrder(dimensions1))
print('Minimum number of scalar multiplications for dimensions2:', matrixChainOrder(dimensions2))
print('Minimum number of scalar multiplications for dimensions3:', matrixChainOrder(dimensions3))

DNA1 = "ATGCTAGCTGACTGATCGATCGATCGATCGATCGATCGATCGATCGATCG" 
DNA2 = "TGCTAGCTGACTGATCGATCGATCGATCGATCGATCGATCGATCGATCGA" 
print('\nAlgoritma Longest Common Subsequence dengan dynamic programming')
print('Longest common subsequence:', lcs(DNA1, DNA2))
