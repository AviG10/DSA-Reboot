// Problem Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// Brute Force - Linear Search
// Time Complexity - O(n)
// Space Complexity - O(1)
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size(), firstIndex = -1, lastIndex = -1;

//         for(int i = 0;i < n;i++){
//             if(nums[i] == target) {
//                 if(firstIndex == -1) {
//                     firstIndex = i;
//                     lastIndex = i;
//                 }
//                 else{
//                     lastIndex = i;
//                 }
//             }
//         }

//         return {firstIndex, lastIndex};
//     }
// };


// Optimized Solution - Binary Search - Lower_Bound & Upper_Bound
// Time Complexity - O(logn)
// Space Complexity - O(1)
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size(); 
//         int lowerBound = lower_bound(nums.begin(),nums.end(),target) - nums.begin();

//         if((lowerBound == n) || (nums[lowerBound] != target)) return {-1,-1};

//         int upperBound = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
//         return {lowerBound, upperBound - 1};
//     }
// };


// Optimized Solution - Binary Search
// Time Complexity - O(logn)
// Space Complexity - O(1)
class Solution {
    private: 
        int firstOccurence(vector<int>& nums, int &target){
            int n = nums.size();
            int low = 0, high = n-1;
            int ans = -1;
            
            while(low <= high){
                int mid = low + (high - low)/2;
    
                if(nums[mid] == target) ans = mid, high = mid-1;
                else if(nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
    
            return ans;
        }
    
        int lastOccurence(vector<int>& nums, int &target){
            int n = nums.size();
            int low = 0, high = n-1;
            int ans = -1;
            
            while(low <= high){
                int mid = low + (high - low)/2;
    
                if(nums[mid] == target) ans = mid, low = mid + 1;
                else if(nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
            
            return ans;
        }
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int firstOccur = firstOccurence(nums,target);
            if(firstOccur == -1) return {-1,-1};
            
            int lastOccur = lastOccurence(nums,target);
            return {firstOccur,lastOccur};
        }
    };
    
    