class Solution {
public:
    int reverse(int x) {
        int rem, ans = 0;  // Initialize remainder and the result.
        
        while (x != 0) {  // Continue until all digits are processed.
            rem = x % 10;  // Get the last digit of x.
            
            // Check for overflow before updating ans.
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) return 0;
            
            ans = ans * 10 + rem;  // Shift ans and add the last digit.
            x /= 10;  // Remove the last digit from x.
        }
        
        return ans;  // Return the reversed integer.
    }
};
