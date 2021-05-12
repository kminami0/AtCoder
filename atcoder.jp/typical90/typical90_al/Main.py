import math

def lcm(x, y):
  return (x * y) // math.gcd(x, y)

A, B = map(int,input().split())

if lcm(A, B) > 1000000000000000000:
  print("Large")
else:
  print(lcm(A, B))