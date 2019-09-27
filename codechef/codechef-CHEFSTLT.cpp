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
    int n,l,x,y;
    string s1,s2;
    cin >> n;
    while(n--){
    	x=y=0;
    	cin >> s1 >> s2;
    	l = s1.length();
    	for(int i=0;i<l;++i){
    		if((s1[i]=='?' && s2[i]=='?') || (s1[i]=='?' || s2[i]=='?')){
    			y++;
    		}else if(s1[i]!=s2[i]){
    			x++;
    			y++;
    		}
    	}
    	cout << x << " " << y << endl;
    }
    return 0;
}