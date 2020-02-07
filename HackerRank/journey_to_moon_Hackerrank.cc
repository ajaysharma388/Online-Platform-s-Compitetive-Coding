#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define endl "\n"

class Graph{
	ll v;
	list<int> *adjList;
	public:
	// Default Constructor.
	Graph(const ll v) {
		this->v = v;
		this->adjList = new list<int>[this->v];
	}
	// Adding the Edge into the graph.
	void addEdge(int u,int v) {
		this->adjList[u].push_back(v);
		this->adjList[v].push_back(u);
	}
	// 	Printing The Adjacency List.
	void printAdjList() {
		for(int i = 0; i < this->v; ++i) {
			cout << i << " --> ";
			for(auto node : this->adjList[i]) {
				cout << node<< " , ";
			}
			cout << endl;
		}
	}
	ll dfsHelper(int node,bool *visited) {
		visited[node] = true;
		ll count = 1;
		for(auto neighbour : this->adjList[node]) {
			if(!visited[neighbour]) {
				count += dfsHelper(neighbour,visited);
			}
		}
		return count;
	}
	ll dfsMoon() {
		bool *visited = new bool[this->v];
		for(int i = 0; i < this->v; ++i) {
			visited[i] = false;
		}
		ll ans = ((this->v) * (this->v - 1))/2;
		for(int i = 0; i < this->v; ++i) {
			if(!visited[i]) {
				ll count = dfsHelper(i,visited);
				ans -= (count*(count-1))/2;
			}
		}
		return ans;
	}
};


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,e;
	cin >> n >> e;
	Graph g(n);
	for(int i = 0; i < e; ++i) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u,v);
	}
	cout << g.dfsMoon() << endl;
	return 0;
}

// Sample Input :

// 5 3
// 0 1
// 2 3
// 0 4

// 100000 2
// 1 2
// 3 4

// 4 1
// 0 2

// Sample Output :

// 6
// 4999949998
// 5