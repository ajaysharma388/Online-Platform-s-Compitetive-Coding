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
	int n;
	cin >> n;
	while(n--){
		float gr,sal,hra,da;
		cin >> sal;
		if(sal<1500){
			hra=sal/10;
			da=sal*9/10;
		}else{
			hra=500;
			da=sal*98/100;
		}
		gr=sal+hra+da;
		printf("%.2f\n",gr);
	}
	return 0;
}