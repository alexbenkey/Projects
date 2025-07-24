f = open("./data", "r")
line = []
total = 0

def check_safety(arr):
    original = arr
    for i in range(len(original)):
        dup = original[:]
        dup.pop(i)
        print(dup)
        if (is_strictly_decreasing(dup) or is_strictly_increasing(dup)):
            if is_in_safe_range(dup):
                return(1)
            else:
                print("not in safe range")
        else:
            print("not increasing or decreasing")
    return(0)


def is_strictly_increasing(arr):
    return all(arr[i] < arr[i + 1] for i in range(len(arr) - 1))

def is_strictly_decreasing(arr):
    return all(arr[i] > arr[i + 1] for i in range(len(arr) - 1))

def is_in_safe_range(arr):
    return all(( -3 <= (arr[i] - arr[i + 1]) <= 3) for i in range(len(arr) - 1))

for i in f:
    line = i.split()
    line = [int(z) for z in line]
    total += check_safety(line)
print(total)

# print("\n\n\ntotal: ")
# print(total)

    # if((line[0] < line[1] < line[2] < line[3] < line[4]) or (line[0] > line[1] > line[2] > line[3] > line[4])):
    #     if (-3 <= (line[0] - line[1]) <= 3) and (-3 <= (line[1] - line[2]) <= 3) and (-3 <= (line[2] - line[3]) <= 3) and (-3 <= (line[3] - line[4]) <= 3):
    #         print("safe")
    #         total += 1
    #     else:
    #         print("unsafe, not al values are between -3 and 3")
    # else:
    #     print("unsafe, not all decreasing or increasing")

# print(total)