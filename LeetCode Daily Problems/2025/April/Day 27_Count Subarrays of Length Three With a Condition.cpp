// 3392. Count Subarrays of Length Three With a Condition
// Problem link: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27


class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size(), count = 0;
    
            for(int i = 2;i < n;i++){
                if(2*(nums[i-2]+nums[i]) == nums[i-1]){
                    count++;
                }
            }
    
            return count;
        }
    };
    
