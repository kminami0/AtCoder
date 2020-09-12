N = int(input())
p = [int(input()) for i in range(N)]
ans = 0
for i in p:
  ans += i
ans -= int(max(p)/2)
print(ans)