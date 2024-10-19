class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to keep track of opening parentheses

        // Loop through each character in the string
        for (char c : s) {
            // If the character is an opening bracket, push it onto the stack
            if (c == '{' || c == '(' || c == '[') {
                st.push(c);
            }
            // If the character is a closing bracket
            else {
                // If the stack is empty, it means we have an unmatched closing bracket
                // Also, check if the top of the stack matches the corresponding opening bracket
                if (st.empty() ||
                   (c == ')' && st.top() != '(') ||
                   (c == '}' && st.top() != '{') ||
                   (c == ']' && st.top() != '[')) {
                    return false;  // If conditions are not met, return false
                }

                // If the brackets match, pop the top element from the stack
                st.pop();
            }
        }

        // After processing all characters, the stack should be empty if the string is valid
        return st.empty();
    }
};
