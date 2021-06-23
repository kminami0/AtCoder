A, B = map(int, input().split())
print(max(A+B, max(A-B, A*B)))