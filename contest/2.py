length = input()
array = [int(n) for n in input().split()]
array.sort()
if length == 2:
    print(array[0] * array[1])
elif length == 3:
    print(max(max(array[0] * array[1], array[0] * array[2]), array[1] * array[2]))
else:
    print(max(array[0] * array[1], array[-1] * array[-2]))
