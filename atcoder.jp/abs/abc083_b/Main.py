N, A, B = map(int, input().split())
ans = 0
for i in range(N+1):
  s = 0
  t = i
  u = i
  for j in range(5):
    s += t % 10
    t //= 10
  if A <= s and s <= B:
    ans += u
print(ans)