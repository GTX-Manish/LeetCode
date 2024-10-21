class Solution(object):
    def combinationSum(self, candidates, target):
        res = []  # Result list to store all valid combinations

        # Helper function for backtracking
        # idx: current index in candidates, comb: current combination, total: current sum
        def make_combination(idx, comb, total):
            # If the current sum equals the target, add a copy of the combination to the result
            if total == target:
                res.append(comb[:])  # Make a copy of the combination before adding
                return

            # If the current sum exceeds the target or we've processed all candidates, backtrack
            if total > target or idx >= len(candidates):
                return

            # Include the current candidate in the combination
            comb.append(candidates[idx])
            # Recur with the same index (allowing reuse of the same element) and updated sum
            make_combination(idx, comb, total + candidates[idx])

            # Backtrack by removing the last element and trying the next candidate
            comb.pop()
            # Recur with the next index (to try the next candidate)
            make_combination(idx + 1, comb, total)

        # Initial call to the helper function starting from index 0 with an empty combination
        make_combination(0, [], 0)

        return res
