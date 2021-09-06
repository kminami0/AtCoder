A, B, C = map(int, input().split())
if max(A, B, C) == A:
  print(10*A+B+C)
elif max(A, B, C) == B:
  print(10*B+C+A)
else:
  print(10*C+A+B)