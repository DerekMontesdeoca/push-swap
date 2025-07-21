import random
import sys

for _ in range(int(sys.argv[1])):
    print(random.randint(-2147483648, 2147483647))

