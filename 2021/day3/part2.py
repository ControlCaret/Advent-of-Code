with open("input.txt") as file:
    line = [data.strip() for data in file]

o2 = line
for j in range(len(o2[0])):
    num0 = 0
    num1 = 0
    for i in range(len(o2)):
        if int(o2[i][j]) == 1:
            num1 += 1
        else:
            num0 += 1  
    if num0 > 0 and num1 > 0:
        if num1 >= num0:
            o2 = list(filter(lambda a : int(a[j]) == 1, o2))
        
        if num0 > num1:
            o2 = list(filter(lambda a : int(a[j]) == 0, o2))

co2 = line
for j in range(len(co2[0])):
    num0 = 0
    num1 = 0
    for i in range(len(co2)):
        if int(co2[i][j]) == 1:
            num1 += 1
        else:
            num0 += 1 
    if num0 > 0 and num1 > 0:
        if num1 >= num0:
            co2 = list(filter(lambda a : int(a[j]) == 0, co2))
        if num0 > num1:
            co2 = list(filter(lambda a : int(a[j]) == 1, co2))

print(int(o2[0], 2) * int(co2[0], 2))
