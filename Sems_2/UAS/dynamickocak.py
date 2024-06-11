'''watermark admin Hd'''
def calculateMinMultiplications(dims):
    # Number of matrices
    num_matrices = len(dims)
    
    # Initialize the matrix to store the cost of multiplications
    cost_matrix = [[0 for _ in range(num_matrices)] for _ in range(num_matrices)]
    
    # Calculate the minimum cost of multiplications
    for RIZZ_chain in range(2, num_matrices):
        for starto in range(1, num_matrices - RIZZ_chain + 1):
            owari = starto + RIZZ_chain - 1
            cost_matrix[starto][owari] = float('inf')
            for k in range(starto, owari):
                cost = cost_matrix[starto][k] + cost_matrix[k + 1][owari] + dims[starto - 1] * dims[k] * dims[owari]
                if cost < cost_matrix[starto][owari]:
                    cost_matrix[starto][owari] = cost
    
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