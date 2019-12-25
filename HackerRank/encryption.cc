#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

float root(int n){
	float num=0;
	float inc=1;
	int msb = 3;
	while(msb && num*num!=n){
		num+=inc;
		if(num*num>n){
			num-=inc;
			inc/=10.0;
			msb--;
		}
	}
	return num;
}

string encryption(string s) {
	int row = floor(root(s.length()));
	int col = ceil(root(s.length()));
	if(s.length()>row*col){
		row++;
	}
	char mat[row][col];
	int k=0;
	for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
			mat[i][j] = s[k];
			k++;
		}
	}
	s = "";
	for(int j=0;j<col;++j){
		for(int i=0;i<row;++i){
			if(mat[i][j]>='a' && mat[i][j]<='z'){
				s+=mat[i][j];
			}
		}
		s+=' ';
	}
	return s;
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
		string s;
		cin >> s;
		cout<<encryption(s)<<endl;
	}
	return 0;
}

// Sample Input :

// 3
// haveaniceday
// chillout
// feedthedog

// Sample Output :

// hae and via ecy 
// clu hlt io 
// fto ehg ee dd 