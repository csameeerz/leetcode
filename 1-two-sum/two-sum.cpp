class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        
        s[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (s.find(target - nums[i]) != s.end()) return {i, s[target - nums[i]]};
            s[nums[i]] = i;;
        }

        return {0, 0};
    }
};