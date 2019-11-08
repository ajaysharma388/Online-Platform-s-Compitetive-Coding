#include <iostream>

using namespace std;

int main(){
	int x=0,y=0;
	char s[200];
	cin>>s;
	for(int i=0;s[i]!='\0';++i){
		if(s[i]=='L') x--;
		else if(s[i]=='R') x++;
		else if(s[i]=='D') y--;
		else y++;
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}