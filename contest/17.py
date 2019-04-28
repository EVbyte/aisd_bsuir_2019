num = int(input())
i = 0
multipliers1 = [1021, 1031, 1033]
multipliers2 = [1021*1031, 1021*1033, 1031*1033]
number = 1021*1031*1033

multipliers = []

while i < num:
    n = int(input())
    if n in multipliers1 or n in multipliers2 or n == number:
        multipliers.append(n)
    i += 1

answer = (set(multipliers1).issubset(multipliers)
          or (multipliers1[0] in multipliers and multipliers2[2] in multipliers)
          or (multipliers1[1] in multipliers and multipliers2[1] in multipliers)
          or (multipliers1[2] in multipliers and multipliers2[0] in multipliers)
          or (number in multipliers))

print ("YES" if answer else "NO")


