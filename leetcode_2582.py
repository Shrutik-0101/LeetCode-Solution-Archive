# Process
# Initialization:
# position represents the current position of the pillow, starting with the first person.
# direction indicates the direction of passing:
# 1 for forward and -1 for backward.

# Loop to Simulate Passing the Pillow:
# The loop runs until time becomes zero.
# In each iteration, position is updated based on the direction.
# If position reaches n, the direction is changed to -1 to start moving backward.
# If position reaches 1, the direction is changed to 1 to start moving forward.

# Return the Result:
# return position
# The function returns the final position of the pillow.

# Solution
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        position = 1
        direction = 1  # 1 means moving forward, -1 means moving backward
        
        while time > 0:
            position += direction
            time -= 1
            if position == n:
                direction = -1  # Start moving backward
            elif position == 1:
                direction = 1  # Start moving forward
        
        return position