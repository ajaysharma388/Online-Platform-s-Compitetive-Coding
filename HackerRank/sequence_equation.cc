#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

vector<int> permutationEquation(vector<int> p) {
    vector<int> v;
    map<int,int> x;
    for(int i=0;i<p.size();++i){
        x[p[i]] = i+1;
    }
    for(auto node:x){
        int t = node.second;
        v.push_back(x[t]);
    }
    return v;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;++i){
			cin >> v[i];
		}
		vector<int> vec = permutationEquation(v);
		for(int i=0;i<vec.size();++i){
			cout<<vec[i]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}

// Sample Output : 

// 3
// 5
// 5 2 1 3 4
// 5
// 4 3 5 1 2
// 3
// 2 3 1

// Sample Input :

// 4 2 5 1 3 
// 1 3 5 4 2 
// 2 3 1 