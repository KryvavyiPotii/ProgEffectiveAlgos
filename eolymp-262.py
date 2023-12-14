'''
This task was done by using the dynamic programming method.
Out subtask is: find the stair with maximum value among the former k stairs.
More details will be added during the colloquium :)
'''

n = int(input())
# Separate stairs by " ", convert string to ints and
# add the first and the last stairs
stairs = [0] + [int(x) for x in input().split()] + [0]
k = int(input())

# Traverse the list skipping the first stair
for i in range(1, n + 2):
    # Store the values of k stairs before current one (i-th)
    previous = [stairs[i - j] for j in range(1, k + 1) if j <= i]
    # Find the highest stair value between previous k stairs and current one (i-th) and
    # set it in the original stair list
    stairs[i] = max(previous, default=0) + stairs[i]
print(stairs[n + 1])
