f = open("data", "r")

def concat(val1, val2):
    return(int(str(val1) + str(val2)))

def get_ans(total, vals):
    totals = []
    if (len(vals)):
        totals = [vals.pop(0)]
    while(len(vals)):
        temp = []
        for val in totals:
            print("val 1: ", int(val), "val 2: ", int(vals[0]))
            temp.append(concat(int(val), int(vals[0])))
            temp.append(int(val) * int(vals[0]))
            temp.append(int(val) + int(vals[0]))
        # print("temp: ")
        # for val in temp:
        #     print(val)
        totals = temp
        vals.pop(0)
    # for val in totals:
    #     print("val: ", val)
    if (total in totals):
        return (total)
    return (0)

total = 0

for line in f:
    answer = line.split(":")
    vals = answer[1].strip()
    answer = answer[0]
    vals = vals.split(" ")
    print("answer: ", answer)
    print("vals: ", vals)
    l = len(vals)
    ans = get_ans(int(answer), vals)
    print("answer_per_line: ", ans)
    total += ans

print(total)