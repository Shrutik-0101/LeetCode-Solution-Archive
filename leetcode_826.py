# Process
# You are given difficulty and profit arrays where difficulty[i] is the difficulty of the ith job and profit[i] is the profit for that job.
# You are also given an array worker where worker[j] is the ability of the jth worker.
# Each worker can complete any job whose difficulty is less than or equal to their ability.
# Maximize the total profit you can achieve.
    
# Solution
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        # Combine difficulty and profit into a list of tuples and sort them by difficulty
        jobs = sorted(zip(difficulty, profit))
        
        # Sort worker abilities
        worker.sort()
        
        max_profit = 0
        best = 0
        i = 0
        n = len(jobs)
        
        for ability in worker:
            # Increase the best profit up to the current worker's ability
            while i < n and jobs[i][0] <= ability:
                best = max(best, jobs[i][1])
                i += 1
            # Add the best profit the current worker can get
            max_profit += best
        
        return max_profit
        
        