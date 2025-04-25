//Problem Link: https://www.geeksforgeeks.org/problems/rotation4723/1

class Solution {
    public:
      int findKRotation(vector<int> &nums) {
          // Ans = Find the index of minimum number
          int n = nums.size(), low = 0, high = n-1, ans = INT_MAX, ind = -1;
          
          while(low <= high){
              int mid = low + (high-low)/2;
              
              if(nums[low] <= nums[mid]) { // left sorted
                  int temp = ans;
                  ans = min(ans, nums[low]);
                  if(temp != ans) ind = low;
                  low = mid+1;
              }
              else{ // Right sorted
                  int temp = ans;
                  ans = min(ans, nums[mid]);
                  if(temp != ans) ind = mid;
                  high = mid-1;
              }
          }
          
          return ind;
      }
  };