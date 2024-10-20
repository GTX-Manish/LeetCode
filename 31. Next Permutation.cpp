class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;  // Initialize index to store the pivot
        int n = nums.size() - 2;  // Start from the second last element

        // Step 1: Find the first index from the end where nums[i] < nums[i+1]
        for (int i = n; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;  // Found the pivot
                break;
            }
        }

        // Step 2: If no pivot was found, reverse the entire array to get the smallest permutation
        if (index == -1) {
            reverse(nums.begin(), nums.end());
        } 
        else {
            // Step 3: Find the first index from the end that is greater than the pivot
            for (int i = nums.size() - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);  // Swap the pivot with this number
                    break;  // Exit the loop after swapping
                }
            }

            // Step 4: Reverse the sequence after the pivot to get the next permutation
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};
