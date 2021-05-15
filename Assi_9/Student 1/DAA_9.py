def counting_sort(A, B, k):
    for j in range(0, n):
        C[A[j]] = C[A[j]] + 1

    for i in range(1, k + 1):
        C[i] = C[i] + C[i - 1]

    for j in range(n):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] = C[A[j]] - 1
    return


A = list(map(int, input().strip().split()))
n = len(A)

print("GIVEN :", A)
k = max(A)
B = [0 for i in range(n)]
C = [0 for i in range(0, k + 1)]
counting_sort(A, B, k)
print("OUTPUT :", B)
