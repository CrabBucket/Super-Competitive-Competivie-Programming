database = {}

testcases = input()

for x in range(int(testcases)):
    username = input()
    if not username in database:
        database[username] = 1
        print("OK")
    else:
        print(username + str(database[username]))
        database[username] += 1
