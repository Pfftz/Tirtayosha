'''watermark admin Hd'''
def calculateMinMultiplications(dims):
    # Number of matrices
    num_matrices = len(dims)
    
    # Initialize the matrix to store the cost of multiplications
    cost_matrix = [[0 for _ in range(num_matrices)] for _ in range(num_matrices)]
    
    # Calculate the minimum cost of multiplications
    for chain_length in range(2, num_matrices):
        for start in range(1, num_matrices - chain_length + 1):
            end = start + chain_length - 1
            cost_matrix[start][end] = float('inf')
            for k in range(start, end):
                cost = cost_matrix[start][k] + cost_matrix[k + 1][end] + dims[start - 1] * dims[k] * dims[end]
                if cost < cost_matrix[start][end]:
                    cost_matrix[start][end] = cost
    
    # Return the minimum cost of multiplications
    return cost_matrix[1][num_matrices - 1]

# Test the function with some examples
print('------------------------------------')
print("Abdulhadi - Matrix Chain Multiplication Problem - Abdulhadi")
dims1 = [1, 2, 3, 4, 3]
print('Minimum number of scalar multiplications for dims1:', calculateMinMultiplications(dims1))

dims2 = [5, 10, 3, 12, 5, 50, 6]
print('Minimum number of scalar multiplications for dims2:', calculateMinMultiplications(dims2))

dims3 = [4, 2, 3, 1, 3]
print('Minimum number of scalar multiplications for dims3:', calculateMinMultiplications(dims3))

dims4 = [2, 3, 6, 4, 5]
print('Minimum number of scalar multiplications for dims4:', calculateMinMultiplications(dims4))

dims5 = [2, 7, 3, 6, 4]
print('Minimum number of scalar multiplications for dims4:', calculateMinMultiplications(dims5))
print('------------------------------------')
print("\n Lead Them To Paradise! - Abdulhadi")