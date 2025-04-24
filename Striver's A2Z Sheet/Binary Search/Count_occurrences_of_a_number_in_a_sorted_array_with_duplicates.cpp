// Problem link - https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
class Solution {
    private: 
      pair<int,int> searchRange(vector<int>& nums, int target) {
          int n = nums.size(); 
          int lowerBound = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
  
          if((lowerBound == n) || (nums[lowerBound] != target)) return {-1,-1};
  
          int upperBound = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
          return {lowerBound, upperBound - 1};
      }
    public:
      int countFreq(vector<int>& arr, int target) {
          pair<int,int> ans = searchRange(arr, target);
          
          if(ans.first == -1) return 0;
          else return (ans.second - ans.first+1);
      }
  };