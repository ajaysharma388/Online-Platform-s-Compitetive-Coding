#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int getrank(vector<int> &scores,vector<int> &ranks,int mark){
	int s=0,e=scores.size()-1;
	if(mark>=scores[s]){
		return ranks[s];
	}
	if(mark==scores[e]){
		return ranks[e];
	}
	if(mark<scores[e]){
		return ranks[e]+1;
	}
	int rank=INT_MAX;
	while(s<=e){
		int m=(s+e)/2;
		if(scores[m]>mark && scores[m+1]<mark){
			return ranks[m+1];
		}else if(scores[m]==mark){
			return ranks[m];
		}else if(scores[m]>mark){
			rank = min(rank,ranks[m]);
			s = m+1;
		}else if(scores[m]<mark){
			rank = min(rank,ranks[m]);
			e = m-1;
		}
	}
	return rank;
}

vector<int> climbingLeaderboard(vector<int> &scores, vector<int> &alice) {
    vector<int> ranking;
    int rank = 1;
    int m = scores[0];
    for (int i=0; i < scores.size(); ++i){
    	if(scores[i]<m){
    		m = scores[i];
    		rank++;
    		ranking.push_back(rank);
    	}else{
    		ranking.push_back(rank);
    	}
    }
    vector<int > res;
    for(int i=0;i<alice.size();++i){
        res.push_back(getrank(scores,ranking,alice[i]));
    }
    return res;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n;
	vector<int> mark(n);	
	for(int i=0;i<n;++i){
		cin >> mark[i];
	}
	cin >> m;
	vector<int> alice(m);
	for(int i=0;i<m;++i){
		cin >> alice[i];
	}
	vector<int> res = climbingLeaderboard(mark,alice);
	for(int i=0;i<res.size();++i){
		cout<<res[i]<<endl;
	}
	return 0;
}


// Sample Input : 

// 7
// 100 100 50 40 40 20 10
// 6
// 5 25 50 120 33 45

// Sample Output : 

// 6 
// 4 
// 2
// 1
// 4
// 3