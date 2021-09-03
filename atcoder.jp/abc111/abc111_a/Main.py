n = input()
n_list = list(n)
for i in range(3):
  if n_list[i] == '1':
    n_list[i] = '9'
  else:
    n_list[i] = '1'
n_changed = "".join(n_list)
print(n_changed)