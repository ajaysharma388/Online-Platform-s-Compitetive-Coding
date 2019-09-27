#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int sum(int b){
	int sum=0;
	for(int i=1;i<=b;++i){
		sum+=i;
	}
	return sum;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
    	int a,b,res=0;
		cin >> a >> b;
		for(int i=1;i<=a;++i){
			res = sum(max(res,b));
		}
		cout<<res<<endl;
    }
	return 0;
}