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
    int n,m,x,y;
    cin >> n;
    while(n--){
        int count=0;
        cin>>m>>x>>y;
        int sp = x*y;
        int *cops = new int[m];
        for(int i=0;i<m;++i){
            cin >> cops[i];
        }
        sort(cops,cops+m);
        for(int i=0;i<m-1;++i){
            if(cops[i+1]-cops[i]-1>2*sp){
                count+=(cops[i+1]-cops[i]-1-2*sp);
            }
        }
        if(cops[0]-1>sp) count+=(cops[0]-1-sp);
        if(100-cops[m-1]>sp) count+=(100-cops[m-1]-sp);
        delete []cops;
        cout<<count<<endl;
    }
    return 0;
}