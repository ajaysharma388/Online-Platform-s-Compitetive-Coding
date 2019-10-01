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
    int t,xs,ys,xd,yd;
    cin >> t;
    while(t--){
        cin >> xs >> ys >> xd >> yd;
        xd-=xs;
        yd-=ys;
        if(xd>0&&yd==0) cout<<"right\n";
        else if(yd>0&&xd==0) cout<<"up\n";
        else if(xd<0&&yd==0) cout<<"left\n";
        else if(yd<0&&xd==0) cout<<"down\n";
        else cout<<"sad\n";
    }
    return 0;
}