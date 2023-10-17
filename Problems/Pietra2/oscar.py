
x = [5, 4, 5, 3, 2]
q = [1, 2, 3, 4, 5]

max = x[len(x)-1]
x[len(x)-1] = 1

for i in range(len(x)-2, -1, -1):

    print(x[i])
    if x[i] > max:
        max = x[i]
        x[i] = 1
    elif x[i] == max:
        print(x)
        x[i] = x[i+1] + 1
    else:
        x[i] = x[i+1]
  
for i in range(len(q)):
    q[i] = x[q[i] - 1]

print(q)