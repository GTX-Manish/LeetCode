class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;         // Initialize a counter for the number of duplicates found
        int n = nums.size();   // Get the size of the input vector

        // Start iterating from the second element (index 1)
        for (int i = 1; i < n; i++) {
            // If the current element is the same as the previous one, it is a duplicate
            if (nums[i] == nums[i - 1]) {
                count++;  // Increment the duplicate counter
            } 
            // If the current element is different, move it to the 'next' position in the array
            else {
                nums[i - count] = nums[i];  // Place the non-duplicate element at the correct position
            }
        }
        
        // The new length of the array with unique elements is the original size minus the duplicates found
        return n - count;  
    }
};
