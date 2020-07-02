import sys

def reverse(n, base):
	result = 0
	while n > 0:
		result *= base
		result += n % base
		n //= base
	return result

def isPalindrome(n, base):
	return n == reverse(n, base)

def length(n, base):
	length = 0
	while n > 0:
		length += 1
		n //= base
	return length

for line in sys.stdin:
	unpack = line.split()
	base, n = int(unpack[0]), int(unpack[1])
	count = 0
	while not isPalindrome(n, base) and count <= 500:
		n = n + reverse(n, base)
		count += 1
	
	if count > 500:
		print(">500")
	else:
		print(count, length(n, base))
