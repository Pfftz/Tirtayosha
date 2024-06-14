#watermark ADMIN Hd
def fibonaccia(n):
    fibonia = [0, 1] + [0]*(n-1)
    for i in range(2, n+1):
        fibonia[i] = fibonia[i-1] + fibonia[i-2]
    return fibonia[n]

def fibonaccia_printing(n):
    fibonia_n = str(fibonaccia(n))
    print(f'Hasilnya adalah {fibonia_n[:10]}... with a total length of {len(fibonia_n)} digits')

fibonaccia_printing(10)
fibonaccia_printing(50)
fibonaccia_printing(100)
fibonaccia_printing(1000)
fibonaccia_printing(10000)
print("\nLead Them To Paradise! - Abdulhadi")