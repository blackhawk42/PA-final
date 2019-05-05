import sys
import uuid

if __name__ == '__main__':
	n = int(sys.argv[1])

	with open("test.txt", "w") as f:
		for i in range(n):
			f.write('{}: {}\n'.format(i, str(uuid.uuid4())))
