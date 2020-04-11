#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"

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

class MinStack {
public:
    /** initialize your data structure here. */
    int i;
    vector<int> stack;
    map<int,int> table;
    MinStack() {
    	i = -1;
        stack.reserve(200);            
    }
    
    void push(int x) {
        stack.push_back(x);
        i++;
        if(table.find(x) == table.end()) {
        	table[x] = 1;
        } else {
        	table[x]++;
        }
    }
    
    void pop() {
    	if(stack.size() == 0) return;
    	int top = stack[i];
    	stack.pop_back();
    	auto it = table.begin();
    	while((*it).second == 0) {
    		table.erase(it);
    		it++;
    	}
    	if(top == (*it).first) {
    		(*it).second--;
    	} else {
    		table[top]--;
    	}
    	i--;
    }
    
    int top() {
        return stack[i];
    }
    
    int getMin() {
        auto it = table.begin();
    	while((*it).second == 0) {
    		table.erase(it);
    		it++;
    	}
    	return (*it).first;
    }
};

int main() {
	fastio(true);
	MinStack s;
	for(int i = 1; i <= 5; ++i) {
		s.push(i);
	}
	s.push(-1);
	cout << s.getMin() << endl;
	// for(int i = 1; i <= 5; ++i) {
	// 	cout << s.top() << endl;
	// 	s.pop();
	// }
	return 0;
}