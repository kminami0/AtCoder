X, Y, A, B = map(int, input().split())
exp = 0
while A*X < X+B:
  if A*X >= Y:
    break
  X *= A
  exp += 1
d = Y - X
p = d // B
if d % B == 0:
  exp += p-1
else:
  exp += p
print(exp)