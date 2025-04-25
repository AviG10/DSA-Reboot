// Problem Link: https://leetcode.com/problems/search-insert-position/
// Time complexity: O(log n)
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        }
    };