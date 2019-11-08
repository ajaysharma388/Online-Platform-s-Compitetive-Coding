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
    int n,k,tw,ot=0;
    string s;
    cin >> n >> k;
    bool tweet[n]={};
    while(k--){
        cin >> s;
        if(s=="CLICK"){
            cin >> tw;
            tweet[tw-1] = (tweet[tw-1])?0:1;
            (tweet[tw-1])?ot++:ot--;
        }else{ 
            ot=0;
            memset(tweet,0,sizeof tweet);
        }
        cout << ot << endl;
    }
	return 0;
}