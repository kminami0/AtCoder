N = int(input())
A = list(map(int, input().split()))
ans = 0
f = False;
while True:
  for i in range(N):
    if A[i] % 2 == 0:
      A[i] /= 2
    else:
      f = True
      break
    if i == N-1:
      ans += 1
  if f:
    break
print(ans)