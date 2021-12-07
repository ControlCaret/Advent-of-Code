# line = open("input.txt").read().splitlines() 

with open("input.txt") as file:
    line = [data.strip() for data in file]

gamma = ''
epsilon = ''

for i in range(len(line[0])):
    num0 = 0
    num1 = 0

    for j in range(len(line)):
        if int(line[j][i]) == 1:
            num1 += 1
        else:
            num0 += 1 

    if num0 > num1:
        gamma += '0'
        epsilon += '1'
    else:
        gamma += '1'
        epsilon += '0'

print(int(gamma, 2) * int(epsilon, 2))
