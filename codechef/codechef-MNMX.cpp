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
    ll t,n;
    cin >> t;
    while(t--){
        ll m,a;
        cin >> n >> a;
        m=a;
        for(int i=1;i<n;++i){
            cin >> a;
            m=min(a,m);
        }
        cout<<m*(n-1)<<endl;
    }
    return 0;
}