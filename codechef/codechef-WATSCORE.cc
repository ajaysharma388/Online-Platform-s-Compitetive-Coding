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
	int testCases;
	cin >> testCases;
	while(testCases--){
		int n;
		cin >> n;
		int chart[12];
		memset(chart,0,sizeof chart);
		int pi,si;
		for(int i=1;i<=n;++i){
			cin >> pi >> si;
			if(chart[pi]){
				chart[pi] = max(chart[pi],si);
			}else{
				chart[pi] = si;
			}
		}
		int score=0;
		for(auto i=1;i<=8;++i){
			score+=chart[i];
		}
		cout << score << endl;
	}	
	return 0;
}