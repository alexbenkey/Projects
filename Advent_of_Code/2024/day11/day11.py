from functools import lru_cache

f = open("data", "r")

# Simulate the splitting behavior for a stone value
@lru_cache(maxsize=200)  # Use LRU caching for this function
def process_stone(value):
    if value == 0:
        return [1]  # Replace 0 with 1
    elif len(str(value)) % 2 == 0:  # If even length
        length = len(str(value)) // 2
        temp1 = int(str(value)[:length])
        temp2 = int(str(value)[length:])
        return [temp1, temp2]  # Return the split parts
    else:
        return [value * 2024]  # Multiply if odd length

# Input and initialization
temp = []
stones = []
blinks = 75

# Parse input (assuming `f` is already an iterable of lines)
for line in f:
    temp.extend(line.split())  # Collect all numbers into temp

# Convert input values to integers
stones = [int(val) for val in temp]

# Main processing loop
while blinks:
    i = 0
    while i < len(stones):
        # Process the current stone using the cached function
        new_values = process_stone(stones[i])
        stones.pop(i)  # Remove the current stone
        for value in reversed(new_values):  # Insert new values
            stones.insert(i, value)
        i += len(new_values) - 1  # Move to the next stone appropriately
    print(76 - blinks)
    blinks -= 1

# temp = []
# stones = []
# blinks = 75

# for line in f: 
#     temp = (line.split(" "))
    
# for val in temp:
#     stones.append(int(val))

# while(blinks):
#     i = 0
#     while(i  < len(stones)):
#         if stones[i] == 0: 
#             stones[i] = 1
#         elif len(str(stones[i])) % 2 == 0:
#             length = int((len(str(stones[i]))) / 2)
#             temp1 = str(stones[i])[0:length]
#             temp2 =  str(stones[i])[length:]
#             stones[i] = int(temp1)
#             i += 1
#             stones.insert(i, int(temp2))
#         else:
#             stones[i] = stones[i] * 2024
#         i += 1
#     print(76 - blinks)
#     blinks -= 1

print(len(stones))