// Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size(), low = 0, high = n - 1, ans = -1;
            
            while (low < high) {
                int mid = low + (high - low) / 2;
    
                if ((high - mid) % 2 == 0) { // Even number of elements in each side
                    if (nums[mid] == nums[mid - 1])
                        high = mid;
                    else if (nums[mid] == nums[mid + 1])
                        low = mid;
                    else {
                        ans = nums[mid];
                        break;
                    }
                } else { // Odd Number of elements in each side
                    if (nums[mid] == nums[mid - 1])
                        low = mid + 1;
                    else if (nums[mid] == nums[mid + 1])
                        high = mid - 1;
                    else {
                        ans = nums[mid];
                        break;
                    }
                }
            }
    
            // If low == high, return any of nums[low] or nums[high] 
            // Example - [1,5,5]
            if(low == high) return nums[low];
    
            return ans;
        }
    };