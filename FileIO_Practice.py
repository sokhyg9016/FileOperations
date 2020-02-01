#file = open("src.txt", "w")
#
#arr = []
#width = 5
#height = 5
#
#for i in range(width):
#    for j in range(height):
#        arr.append(str(i*5 + j + 1))
#
#for val in arr:
#    if not int(val) % 5:
#        if int(val) == 25:
#            file.write(val)
#            break
#        file.write(val + "\n")
#    else:
#        file.write(val +",")
#file.close()

data = open("src.txt", "r")
data = data.read()
data = data.split("\n")

width = len(data)
for index in range(width):
    data[index] = data[index].replace("\n", "").split(",")
    height = len(data[0])

    for j in range(height):
        if int(data[index][j]) < 10:
            data[index][j] = "0" + data[index][j]
        
        data[index][j] = "| " + data[index][j] + " "
    data[index][j] += "|"

# File modify
file = open("dest.txt", "w")

file.write("+----+----+----+----+----+----+----+----+----+----+\n")
for index in range(width):
    for j in range(height):
        file.write(data[index][j])

        if j == height-1 and index != width-1:
            file.write("\n")
file.write("\n+----+----+----+----+----+----+----+----+----+----+")
file.close()
