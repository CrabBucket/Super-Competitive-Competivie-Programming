import sys

fibonacci = [0,1,2]

for i in range(3,51):
  fibonacci.append(fibonacci[i-2] + fibonacci[i-1])

for line in sys.stdin:
  if line == "0\n":
    break
  print(fibonacci[int(line)])