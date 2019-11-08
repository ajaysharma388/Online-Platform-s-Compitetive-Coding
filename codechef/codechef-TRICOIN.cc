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
    ll testCases,coin,height,i;
    cin >> testCases;
    while(testCases--){
        cin >> coin;
        height=0;i=1;
        while(coin>=i){
            coin-=i;
            height++;
            i++;
        }
        cout<<height<<endl;
    }
    return 0;
}