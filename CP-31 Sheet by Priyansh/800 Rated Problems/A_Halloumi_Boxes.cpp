#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int i = 0;i < t;i++){
        int n,k;
        cin >> n >> k;
        
        vector<int> nums(n,0);
        for(int i = 0;i < n;i++){
            cin >> nums[i];
        }

        if(k == 1){
            if(n == 1) cout<<"YES"<<endl;
            else{
                bool flag = true;
                for (int i = 1;i < n;i++){
                    if(nums[i-1] > nums[i]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            } 
        }
        else{ 
            cout<< "YES"<<endl;
        }
    }
    return 0;
}

// Case 1: k = 1
//        |-> n = 1 -> "YES"
//        |-> n > 1 
//              |-> Sorted in non-decreasing order -> "YES"
//              |-> Unsorted in non-decreasing order -> "NO"
// Case 2: k > 1 -> "YES"
