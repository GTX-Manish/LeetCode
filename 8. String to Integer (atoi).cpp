class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int flag = 1;  // To track the sign of the number (1 for positive, -1 for negative).
        int i = 0; 

        // Skip leading whitespace characters.
        while (i < s.length() && s[i] == ' ') i++;

        // Check for optional '+' or '-' sign.
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) { 
            flag = (s[i] == '-') ? -1 : 1;  // Set flag based on the sign.
            i++;
        }

        // Convert the numeric part of the string.
        while (i < s.length() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');  // Build the number.
            
            // Check for overflow or underflow conditions.
            if (ans * flag <= INT_MIN) return INT_MIN;  // Handle underflow.
            if (ans * flag >= INT_MAX) return INT_MAX;  // Handle overflow.
            i++;
        }
        
        return ans * flag;  // Return the final result with the correct sign.
    }
};
