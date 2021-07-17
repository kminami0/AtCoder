N, K = map(int, input().split())
S = input()

for i in range(N):
  if i == K-1:
    print(S[i].lower(), end="")
  else:
    print(S[i], end="")
print("")