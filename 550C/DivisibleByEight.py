totaliters = 0
def removeEle(string,index):
    return string[:index] + string[index+1:]
dptable = {}
def byEight(num):
    global totaliters
    if num in dptable:
        return dptable[num]
    #print(num)
    if num%8 == 0:
        #print(num)
        dptable[num] = (num,True)
        return (num,True)
    else:
        totaliters+=1
        if num<10:
            dptable[num] = (-1,False)
            return (-1,False)
        index = 0
        number = str(num)
        
        #print(number)
        if totaliters > 100000:
            print("NO")
            exit()
        for _char in number:
            
            temp = byEight(int(removeEle(number,index)))
            if temp[1]:
                dptable[num] = temp
                return temp
            index+=1
        dptable[num] = (-1,False)
        return (-1,False)

case = input()
if '0' in case:
    print("YES")
    print('0')
    exit()

for x in range(len(case))[::-1]:
    if int(case[x]) % 2 != 0:
        continue
    case = case[:x+1]
    break


superodd = True
for char in case:
    if int(char) % 2 == 0:
        superodd = False
        break
    

if superodd:
    print("NO")
    exit()

answer = byEight(int(case))

if answer[1]:

    print("YES")
    print(answer[0])
else:
    print("NO")
