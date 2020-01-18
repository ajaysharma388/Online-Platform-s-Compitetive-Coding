#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Graph{
	int n;
	list<pair<T,int>> *adjList;
	public:
	// Default Constructor.
	Graph(const int size = 0) {
		this->n = size;
		this->adjList = new list<pair<T,int>>[n](); 
	}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,int distance,bool bidir = true) {
		this->adjList[u].push_back(make_pair(v,distance));
		if(bidir) {
			this->adjList[v].push_back(make_pair(u,distance));
		}
	}
	// This is the coding inplementation of Dijktras Algorithm.
	void dijktrasSSSP(T src,vector<int> &res){
		int distance[this->n];
		bool visited[this->n];
		set<pair<int,T>> s;
		for(int i = 0; i < this->n; ++i) {
			distance[i] = INT_MAX;
			visited[i] = false;
		}
		// process the current node.
		distance[src] = 0;
		s.insert({0,src});
		while(!s.empty()) {
			pair<int,T> cur = *(s.begin());
			T cur_node = cur.second;
			int cur_dis = cur.first;
			// processed all the neighbour of current node.
			for(auto pi : this->adjList[cur_node]) {
				if(!visited[pi.first] and 
					distance[cur_node] + pi.second < distance[pi.first]){
					auto it = s.find({distance[pi.first],pi.first});
					if(it != s.end()){
						// erase the conetent.
						s.erase(it);
					}
					distance[pi.first] = distance[cur_node] + pi.second;
					s.insert({distance[pi.first],pi.first});
				}		
			}
			// finallize the current node.
			distance[cur_node] = cur_dis;
			visited[cur_node] = true;
			s.erase(s.begin());
		}
		for(auto i = 0; i < this->n ; ++i) {
			if(distance[i] == INT_MAX) res.push_back(-1);
			else if(distance[i]) res.push_back(distance[i]);
		}
	}
};

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
	Graph<int> g(n);
	for (int i = 0; i < edges.size(); ++i){
		g.addEdge(edges[i][0]-1,edges[i][1]-1,edges[i][2]);
	}
	vector<int> res;
	g.dijktrasSSSP(s-1,res);
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
	int t;
	cin >> t;
	while(t--){
		int n,m,u,s;
		cin >> n >> m ;
		vector<vector<int>> inp(m);
		for(int i=0;i<m;++i){
			for(int j = 0; j < 3; ++j) {
				cin >> u;
				inp[i].push_back(u);
			}
		}
		cin >> s;
		vector<int> res = shortestReach(n,inp,s);
		for(int i = 0; i < res.size(); ++i) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1
// 5 3
// 1 2 10
// 1 3 6
// 2 4 8
// 2

// Sample Output :

// 24 3 15 
// 10 16 8 -1 