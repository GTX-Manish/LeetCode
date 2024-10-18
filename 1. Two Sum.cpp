class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // creating an unordered_map

        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i]; 
            // to check if comp is map or not
            if(mp.count(comp)){
                return {mp[comp], i}; // return if found
            }
            mp[nums[i]] = i;
        }
        return {-1,-1}; // return {-1,-1} if answer not found
    }
};
