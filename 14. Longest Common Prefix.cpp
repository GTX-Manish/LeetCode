class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        // If the vector is empty, return an empty string
        if (n == 0) return "";
        
        // Sort the strings lexicographically. After sorting, the first and last strings
        // will have the minimum and maximum differences, respectively.
        sort(strs.begin(), strs.end());
        
        // After sorting, the common prefix will be shared by the first and last strings.
        string first = strs[0];
        string last = strs[n-1];
        string ans = "";

        // Compare characters of the first and last string until a mismatch is found
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            // If characters at the same position are different, return the result so far
            if (first[i] != last[i]) return ans;
            // If characters match, append to the result
            ans += first[i];
        }

        // Return the accumulated longest common prefix
        return ans;
    }
};
