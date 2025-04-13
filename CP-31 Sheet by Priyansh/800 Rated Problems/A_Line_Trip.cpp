#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i = 0; i < t;i++){
        int n,x;
        cin>>n>>x;
        
        vector<int> nums(n+2,0);
        for(int i = 1;i < n+1;i++){
            cin>>nums[i];
        }
        nums[n+1] = x;

        int min_val = INT_MIN;
        for(int i = 1;i < n+1;i++){
            min_val = max(min_val, (nums[i]-nums[i-1]) );
        }
        min_val = max(min_val,2*(nums[n+1]-nums[n]));

        cout<<min_val<<endl;
    }
    return 0;
}