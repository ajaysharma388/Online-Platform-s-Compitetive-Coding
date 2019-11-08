#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	short int amt;
	float bal;
	cin >> amt >> bal;
	if(amt%5==0 && amt+0.5 <= bal){
		bal-=(amt+0.5);
		cout << fixed << setprecision(2) << bal << endl;
	}else{
		cout << fixed << setprecision(2) << bal << endl;
	}
	return 0;
}