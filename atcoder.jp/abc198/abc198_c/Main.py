R, X, Y = map(int,input().split())
d = X*X + Y*Y
l = 0
r = 1000000009
while r-l>1:
  c = (l+r)//2
  if R*R*c*c < d:
    l = c
  else:
    r = c
  
if r != 1:
  print(r)
elif R*R == d:
  print(1)
else:
  print(2)