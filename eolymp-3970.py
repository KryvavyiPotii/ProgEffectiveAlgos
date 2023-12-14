from collections import Counter

# Skip input (not needed)
n = input()
# Separate animals by " "
animals = input().split()
# Skip input (not needed)
m = input()
# Separate colors by " "
colors = input().split()

# Count every occurence of colors in animals list
c = Counter(animals)

# Print counted occurences
for i in colors:
    print(c[i])
