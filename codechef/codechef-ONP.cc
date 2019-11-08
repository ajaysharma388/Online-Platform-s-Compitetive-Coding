#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void convert(string exp){
	stack<char> s;
	string res;
	for(int i=0;i<exp.length();++i){
		if(exp[i]=='('){
			s.push(exp[i]);
		}else if(exp[i]>=97 && exp[i]<=122){
			res+=exp[i];
		}else if(exp[i]==')'){
			while(s.top()!='('){
				res+=s.top();
				s.pop();
			}
			s.pop();
		}else{
			if(s.top()=='('){
				s.push(exp[i]);
			}
		}
	}
	cout<<res<<endl;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	string exp;
	char res[100];	
	int n;
	cin >> n;
	while(n--){
		cin >> exp;
		convert(exp);
	}
	return 0;
}
