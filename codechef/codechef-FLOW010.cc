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
	int n;
	cin>>n;
	char id;
	while(n--){
		cin>>id;
		if(id=='b' || id=='B') cout<<"BattleShip"<<endl;
		else if(id=='c' || id=='C') cout<<"Cruiser"<<endl;
		else if(id=='d' || id=='D') cout<<"Destroyer"<<endl;
		else cout<<"Frigate"<<endl;
	}
	return 0;
}