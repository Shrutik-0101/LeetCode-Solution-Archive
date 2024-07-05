# Process
# Initialization and Early Return:
# Initializes variables and checks if the list is too short.
# Think about why lists with fewer than three nodes can't have critical points.

# Identifying Critical Points:
# Loops through the list to find local maxima and minima.
# Consider how a node's value compared to its neighbors indicates a critical point.

# Storing Positions and Tracking Distance:
# Stores positions of critical points and calculates the minimum distance between them.
# Reflect on how the positions help in determining both minimum and maximum distances.

# Final Checks and Return:
# Checks if there are enough critical points and returns the distances.
# Think about how to handle cases with fewer than two critical points.

# Solution
class Solution:
    # Function
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        prev = head
        head = head.next
        critical_pos = []
        curr = 1
        mindis = sys.maxsize

        if(head.next==None):
            return [-1, -1]

        while(head.next!=None):
            nextel = head.next
            if(prev.val<head.val and nextel.val<head.val):
                critical_pos.append(curr)
            elif(prev.val>head.val and nextel.val>head.val):
                critical_pos.append(curr)

            if(len(critical_pos)>1):
                mindis = min(mindis, critical_pos[-1]-critical_pos[-2])
            curr+=1
            prev = head
            head = head.next

        if(len(critical_pos)<=1):
            return [-1, -1]

        answer = [mindis, critical_pos[-1]-critical_pos[0]]

        return answer