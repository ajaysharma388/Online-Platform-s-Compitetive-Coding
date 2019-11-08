#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int main(){
    #ifndef ONLINE_JUGDE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string digit;
    cin >> t;
    while(t--){
        cin >> digit;
        int sum=0,length=digit.length();
        for(int i=0;i<length;++i)
            if(digit[i]=='1')
                sum++;
        if(sum==1 || length-sum==1) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
