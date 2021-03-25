R, B = map(int, input().split())
x, y = map(int, input().split())
l = 0
r = max(R, B)
while r-l > 1:
  c = (l+r) // 2
  if R < c or B < c:
    r = c
    continue
  p = (R-c) // (x-1)
  q = (B-c) // (y-1)
  if p+q >= c:
    l = c
  else:
    r = c

print(l)