n = int(input())

l = 1
r = n + 10
while r-l > 1:
  c = (l+r) // 2
  if c*(c+1)//2 <= n+1:
    l = c
  else:
    r = c

print(n-l+1)