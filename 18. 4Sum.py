class Solution(object):
    def fourSum(self, nums, target):
        # Sort the input list to make it easier to use the two-pointer approach
        nums.sort()
        
        s = set()    # A set to store unique quadruplets (avoids duplicates)
        output = []  # The list to store the final result

        # Iterate over the list using two nested loops for the first two numbers
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                k = j + 1      # Third pointer starts right after the second pointer (j)
                l = len(nums) - 1  # Fourth pointer starts at the end of the array

                # Use the two-pointer approach to find valid quadruplets
                while k < l:
                    sum = nums[i] + nums[j] + nums[k] + nums[l]  # Calculate the sum of the quadruplet

                    # If the sum matches the target, add the quadruplet to the set
                    if sum == target:
                        s.add((nums[i], nums[j], nums[k], nums[l]))  # Add tuple to set to avoid duplicates
                        k += 1  # Move the third pointer right to find the next possible pair
                        l -= 1  # Move the fourth pointer left to find the next possible pair
                    elif sum < target:
                        k += 1  # If the sum is less than the target, move the third pointer to increase the sum
                    else:
                        l -= 1  # If the sum is greater than the target, move the fourth pointer to decrease the sum

        # Convert the set of tuples to a list of lists
        output = list(s)

        return output  # Return the list of unique quadruplets
