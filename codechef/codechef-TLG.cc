#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,sa=0,sb=0,m=0,mp=0,w;
	cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;++i){
		int temp;
		cin >> temp;
		sa += temp;
		a[i] = sa;
		cin >> temp;
		sb += temp;
		b[i] = sb;
		m = max(m,abs(a[i]-b[i]));
		if(m!=mp && a[i]>b[i]) w=1;
		if(m!=mp && a[i]<b[i]) w=2;
		mp = m;
	}
	cout << w << " " << m << endl;
	return 0;
}