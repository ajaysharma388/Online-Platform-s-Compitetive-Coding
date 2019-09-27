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
    int t,l; cin >> t;
    string s1,s2;
    while(t--){
        cin >> s1 >> s2;
        l=s1.length();
        int i;
        for(i=0;i<l;++i){
            if(s1[i]!=s2[i] && s1[i]>=97 && s2[i]>=97){
                cout<<"No"<<endl;
                break;
            }
        }
        if(i==l) cout<<"Yes"<<endl;
    }
    return 0;
}