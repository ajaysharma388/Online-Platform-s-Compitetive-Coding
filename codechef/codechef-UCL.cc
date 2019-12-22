#include<bits/stdc++.h>
using namespace std;

bool customsort(pair<int,string> &a,pair<int,string> &b){
	return a.first>b.first;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,N;cin>>T;
	while(T--){
		N=12;
		map<string,pair<int,int> > match;
		string str,str1,str2;
		int g1,g2;
		while(N--){
			cin>>str1>>g1>>str>>g2>>str2;
			if(match.count(str1)>0){
				if(g1<g2){
					match[str1].first+=0;
				}else if(g1>g2){
					match[str1].first+=3;
				}else{
					match[str1].first+=1;
				}
				match[str1].second+=g1-g2;
			}else{
				if(g1<g2){
					match[str1].first=0;
				}else if(g1>g2){
					match[str1].first=3;
				}else{
					match[str1].first=1;
				}
				match[str1].second=g1-g2;
			}
			if(match.count(str2)>0){
				if(g1>g2){
					match[str2].first+=0;
				}else if(g1<g2){
					match[str2].first+=3;
				}else{
					match[str2].first+=1;
				}
				match[str2].second+=g2-g1;
			}else{
				if(g1>g2){
					match[str2].first=0;
				}else if(g1<g2){
					match[str2].first=3;
				}else{
					match[str2].first=1;
				}
				match[str2].second=g2-g1;
			}
		}
		map<string,pair<int,int> >::iterator it;
		vector<pair<int,string> > V;
		for(it=match.begin();it!=match.end();it++){
			V.push_back(make_pair(it->second.second,it->first));
		}
		sort(V.begin(),V.end(),customsort);
		for(int i=0;i<V.size();i++){
			V[i].first=match[V[i].second].first;
		}
		sort(V.begin(),V.end(),customsort);
		cout<<V[0].second<<" "<<V[1].second<<"\n";
	}
	return 0;
}