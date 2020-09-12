N, D = map(int, input().split())
X = [list(map(int, input().split())) for i in range(N)]
ans = 0
for i in range(N):
  for j in range(i+1, N):
    d = 0
    for k in range(D):
      d += (X[i][k] - X[j][k]) ** 2
    d **= 0.5
    if d.is_integer():
      ans += 1
print(ans)