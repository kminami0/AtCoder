K, X = map(int, input().split())
if -100000 <= X-K+1 and X+K-1 <= 100000:
  for i in range(K*2-2):
    print(X-K+1+i, end="")
    print(" ", end="")
  print(X+K-1)
  
if X-K+1 < -100000:
  for i in range(-100000, X+K-1):
    print(i, end="")
    print(" ", end="")
  print(X+K-1)

if X+K-1 > 100000:
  for i in range(X-K+1, 100000):
    print(i, end="")
    print(" ", end="")
  print(100000)