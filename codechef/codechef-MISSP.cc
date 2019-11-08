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
    int t,n,type,a;
    cin >> t;
    while(t--){
        type=0;
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> a;
            type^=a;
        }
        cout<<type<<endl;
    }
    return 0;
}