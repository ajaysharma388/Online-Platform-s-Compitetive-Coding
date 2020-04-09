#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define mod 1000000007

template<typename T>
class Graph{
	map<T,list<T>> adjList;
	public:
	// Default Constructor.
	Graph() {}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,bool bidir = true) {
		this->adjList[u].push_back(v);
		if(bidir) {
			this->adjList[v].push_back(u);
		}
	}
	// Printing The Adjacency List.
	void printAdjList() {
		for(auto node : this->adjList) {
			T u = node.first;
			cout << u << " --> ";
			for(T vertex : this->adjList[u]) {
				cout << vertex << ", ";
			}
			cout << endl;
		}
	}
	pair<bool,ll> dfsProd(T src,T des,ll*cost,map<T,bool>&visited) {
		visited[src] = true;
		if(src == des) return {true,cost[src]};
		ll product = cost[src];
		for(auto node : this->adjList[src]) {
			if(!visited[node]) {
				auto res = dfsProd(node,des,cost,visited);
				if(res.first) return {true,res.second*product};		  				
			}
		}
		return {false,1};
	}

	ll getProduct(T src,T des,ll *cost) {
		map<T,bool> visited;
		return dfsProd(src,des,cost,visited).second % mod;
	}
};

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

ll factors(ll num) {
	ll count = 0;
	for(ll i = 1; i <= num/2; ++i) 
		if(num%i == 0) count++;
	return count+1;
}

int main() {
	fastio(true);
	ll t;
	cin >> t;
	while(t--) {
		ll V,E;
		cin >> V;
		ll *cost = new ll[V+1]();
		E = V-1;
		Graph<ll> g;
		for(ll i = 1; i <= E; ++i) {
			ll u, v;
			cin >> u >> v;
			g.addEdge(u,v);
		}
		for(ll i = 1; i <= V; ++i) {
			cin >> cost[i];
		}
		ll Q;
		cin >> Q;
		for(ll i = 1; i <= Q; ++i) {
			ll u, v;
			cin >> u >> v;
			cout << factors(g.getProduct(u,v,cost)) << endl;
		}
	}
	return 0;
}

// Sample Input :

// 1
// 5
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6 4 3 5
// 4
// 1 4
// 2 2
// 3 4
// 3 5

// Sample Output :

// 9
// 4
// 15
// 20