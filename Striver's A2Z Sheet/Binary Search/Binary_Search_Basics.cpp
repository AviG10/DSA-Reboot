#include <bits/stdc++.h>
using namespace std;


//Print Array
void printArray(vector<int> &nums){
    for(int i = 0;i < nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}


// Binary Search on sorted Array - Iterative
int binary_search_iterative(vector<int> &nums, int &target){
    int arr_size = nums.size();
    int low = 0, high = arr_size-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}


// Binary Search on sorted Array - Recursive
int binary_search_recursive(vector<int> &nums, int &target, int low, int high){
    if(low > high) return -1;

    int mid = low + (high-low)/2;

    if(nums[mid] == target) return mid;
    else if(nums[mid] < target) return binary_search_recursive(nums, target, mid + 1, high);
    else return binary_search_recursive(nums, target, low, mid - 1);
}


// lower bound of a sorted array
int lower_bound(vector<int> &nums, int &target){
    int n = nums.size();
    int ans = n, low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] < target) low = mid+1;
        else{
            ans = mid;
            high = mid-1;
        }
    }
    
    return ans;
}


// upper bound of a sorted array
int upper_bound(vector<int> &nums, int &target){
    int n = nums.size();
    int ans = n, low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] <= target) low = mid+1;
        else{
            ans = mid;
            high = mid-1;
        }
    }
    
    return ans;
}


// ceil in sorted array
int ceil(vector<int> &nums, int &target){
    return nums[lower_bound(nums,target)];
}


// floor in sorted array
int floor(vector<int> &nums, int &target){
    int n = nums.size();
    int ans = -1;
    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(nums[mid] > target) high = mid-1;
        else {
            ans = nums[mid];
            low = mid+1;
        }
    }

    return ans;
}


int main(){
    int n;
    cin>>n;

    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }

    //print Array to check input 
    printArray(nums);


    // Binary Search on sorted Array - Iterative
    // Time Complexity - O(log n)
    int target1;
    cin >> target1;
    cout<<binary_search_iterative(nums, target1)<<endl; // returning the index if found, if not return -1


    // Binary Search on sorted Array - Recursive
    // Time Complexity - O(log n)
    int target2;
    cin >> target2;
    cout<<binary_search_recursive(nums, target2, 0, nums.size()-1)<<endl; // returning the index if found, if not return -1


    // lower bound of a sorted array
    // Lower Bound: Smallest Index such that arr[ind] >= x
    int target3;
    cin >> target3;
    cout<<lower_bound(nums,target3)<<endl;
    

    // Upper bound of a sorted array
    // Upper Bound: Smallest Index such that arr[ind] > x
    int target4;
    cin >> target4;
    cout<<upper_bound(nums,target4)<<endl;

    // ceil in sorted array
    // ceil: Smallest no. in array >= x
    int target5;
    cin>>target5;
    cout<<ceil(nums,target5)<<endl;


    // floor in sorted array
    // floor: largest no. in array <= x
    int target6;
    cin>>target6;
    cout<<floor(nums,target6)<<endl;

    return 0;
}

// Input
// 5
// 2 4 6 7 9 
// 5
// 5
// 5
// 6
// 5
// 5


// Expected Output
// 2 4 6 7 9
// -1
// -1
// 2
// 3
// 6
// 4