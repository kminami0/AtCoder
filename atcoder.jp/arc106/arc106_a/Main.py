N = int(input())

for i in range(1, 55):
  for j in range(1, 37):
    if 3**i + 5**j == N:
      print(i, j)
      exit()
      
print(-1)