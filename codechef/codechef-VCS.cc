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
    int t,n,m,k,trig,un_trig,inp;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        bool *track = new bool[n];
        bool *ignored = new bool[n];
        for(int i=0;i<n;++i){
            track[i]=ignored[i]=false;
        }
        for(int i=0;i<m;++i){
            cin >> inp;
            ignored[inp-1] = true;
        }
        for(int i=0;i<k;++i){
            cin >> inp;
            track[inp-1] = true;
        }
        trig=un_trig=0;
        for(int i=0;i<n;++i){
            if(track[i] && ignored[i]) trig++;
            if(!track[i] && !ignored[i]) un_trig++;
        }
        cout<<trig<<" "<<un_trig<<endl;
        delete []track;
        delete []ignored;
    }
    return 0;
}