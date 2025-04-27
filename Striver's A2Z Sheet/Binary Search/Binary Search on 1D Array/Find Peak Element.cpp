// Problem Link: https://leetcode.com/problems/find-peak-element/description/

// Linear Search
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();

//         if(n == 1) return 0; // Case-1: Array consist of only 1 element
//         else if(nums[0] > nums[1]) return 0; // Case - 2: First element is Peak
//         else if(nums[n-1] > nums[n-2]) return (n-1); // Case - 3: Last element is Peak

//         // Case - 4:  All other cases
//         for(int i = 1;i < n-1;i++){
//             if((nums[i] > nums[i-1]) && (nums[i] > nums[i+1])) return i;
//         }
//         return -1;
//     }
// };




//Optimized [ Binary Search ]
class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n = nums.size();
    
            if(n == 1) return 0; // Case-1: Array consist of only 1 element
            else if(nums[0] > nums[1]) return 0; // Case - 2: First element is Peak
            else if(nums[n-1] > nums[n-2]) return (n-1); // Case - 3: Last element is Peak
    
            int low = 1, high = n-2;
    
            while(low <= high){
                int mid = low + (high - low)/2;
    
    
                if((nums[mid] > nums[mid-1]) && (nums[mid] > nums[mid+1])) return mid; // mid is Peak Element
                else if(nums[mid] > nums[mid-1]) low = mid+1; // mid is on increasing curve
                else if(nums[mid] > nums[mid+1]) high = mid-1; // mid is on decreasing curve
                else high = mid-1; // mid is the depression point i.e ((nums[mid] < nums[mid-1]) && (nums[mid] < nums[mid+1]))
            }
    
            return -1;
        }
    };