import re

def find_numeric_pairs(text):
    ret = 0
    pattern = r"mul\((\d{1,3}),(\d{1,3})\)"
    matches = re.findall(pattern, text)
    for i in matches:
        print(i[0], i[1])
        ret += (int(i[0]) * int(i[1]))
        print("ret: ", ret)
    return ret

def extract_between_do_and_dont_with_edges(input_string):
    result = []
    
    dont_first = re.search(r"(.*?)don\'t\(\)", input_string, re.DOTALL)
    if dont_first:
        result.append(dont_first.group(1))
        input_string = input_string[dont_first.end():]
    
    between_matches = re.findall(r'do\(\)(.*?)(don\'t\(\)|$)', input_string, re.DOTALL)
    for match in between_matches:
        result.append(match[0])
        if not match[1]:
            break
    
    return result

f = open("data", "r")
total = 0
total_string = ""
vals = []
for line in f:
    total_string += line
vals = extract_between_do_and_dont_with_edges(total_string)
print(total_string)
print("\n\n\n")
for val in vals:
    print("numeric val return: ", find_numeric_pairs(val))
    total += find_numeric_pairs(val)
print("total: ", total)