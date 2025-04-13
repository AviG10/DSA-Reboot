#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0;i < t;i++){
        int n;
        cin>>n;

        string str;
        cin>>str;

        int max_consec_occur_dots = 0, temp = 0, total_dots = 0;
        for(int i = 0;i < n;i++){
            if(str[i] == '.'){
                temp++;
                total_dots++;
            }
            else{
                temp = 0;
            }
            max_consec_occur_dots = max(max_consec_occur_dots,temp);
        }

        if(max_consec_occur_dots >= 3) cout<< 2<<endl;
        else cout<<total_dots<<endl;

    }
    return 0;
}