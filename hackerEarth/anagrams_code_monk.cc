#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int a[26]={};
		string s;
		cin>>s;
		for(int i=0;i<s.length();++i)
			a[s[i]-97]++;
		cin>>s;
		for(int i=0;i<s.length();++i)
			a[s[i]-97]--;
		int c=0;
		for(int i=0;i<26;++i){
			if(a[i]<0) c+=(-1)*a[i];
			if(a[i]>0) c+=a[i];
		}
		cout<<c<<endl;
	}
	return 0;
}