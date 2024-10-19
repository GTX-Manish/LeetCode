class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
        int i = 0;  // Pointer for the position to place the next non-val element

        // Iterate through the entire array
        for (int k = 0; k < nums.size(); k++) {
            // If the current element is not equal to the specified value
            if (nums[k] != val) {
                // Place the current element at the 'i'th position
                nums[i++] = nums[k];  // Increment 'i' after assigning
            }
        }
        
        // Return the new length of the array (i is the count of non-val elements)
        return i;  
    }
};
