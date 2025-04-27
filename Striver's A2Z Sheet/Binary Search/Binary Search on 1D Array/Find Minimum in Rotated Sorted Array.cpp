//Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// 1. Find the sort half and take the minimum from that
// 2. Eliminate sort half and search in the other part
// 3. Repeat same till low > high
class Solution {
    public:
        int findMin(vector<int>& nums) {
            int n = nums.size(), low = 0, high = n-1, ans = INT_MAX;
    
            while(low <= high){
                int mid = low + (high - low) / 2;
                
                if(nums[low] <= nums[mid]){ // left part sorted
                    ans = min(ans,nums[low]);
                    low = mid+1;
                }
                else{ // Right Part sorted
                    ans = min(ans,nums[mid]);
                    high = mid-1;
                }
            }
    
            return ans;
        }
    };