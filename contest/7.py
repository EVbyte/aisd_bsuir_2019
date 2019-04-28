string = input()
m, n, x1, y1, x2, y2 = (int(n) for n in string.split())
if abs(int(x1) - int(x2)) == abs(int(y1) - int(y2)):
    print("NO")
else:
    print("YES")
