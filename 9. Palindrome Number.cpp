class Solution {
public:
    bool isPalindrome(int x) {
        long long rem = 0;       // Variable to hold the last digit of x.
        long long temp = x;      // Store the original number for comparison.
        long long ans = 0;       // Variable to build the reversed number.

        // If x is negative, it cannot be a palindrome.
        if (x < 0) return false;

        // Reverse the number.
        while (x != 0) {
            rem = x % 10;         // Get the last digit.
            ans = ans * 10 + rem; // Build the reversed number.
            x /= 10;              // Remove the last digit from x.
        }

        // Check if the original number and reversed number are the same.
        return temp == ans;       // Return true if they are equal, otherwise false.
    }
};
