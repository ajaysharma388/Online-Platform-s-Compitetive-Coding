#include <iostream>
#define ll long long
using namespace std;

int main(){
	int t,r,x,y=0;
	float c=0;
	cin>>t;
	while(t--){
		cin>>r>>x;
		if(700*x>=44*r)
			y++;
	}
	cout<<y<<endl;
	return 0;
}