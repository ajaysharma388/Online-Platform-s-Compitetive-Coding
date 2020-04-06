#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool isAnagram(string s1,string s2) {
    int m = s1.length();
    int n = s2.length();
    if(m != n) return false;
    sort(s1.begin(), s1.end()); 
    sort(s2.begin(), s2.end()); 
    for(int i = 0; i < n; ++i) {
        if(s1[i] != s2[i]) return false;
    }
    return true;        
}

bool compare(vector<string> &v1,vector<string> &v2) {
	return v1.size() < v2.size();
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    unordered_map<string ,vector<string>> mp;
    vector<vector<string>> result;
    for(string str : strs) {
        string temp = str;
        sort(temp.begin(), temp.end());
        if(mp.find(temp) != mp.end()) {
            mp[temp].push_back(str);
        } else {
            vector<string> res = {str};
            mp.insert({temp,res});
        }
    }
    for(auto node : mp) {
        sort(node.second.begin(), node.second.end());    
        result.push_back(node.second);
    }
    sort(result.begin(), result.end(),compare);
    return result;        
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
	vector<string> strs;
	for(int i = 0; i < n; ++i) {
		string cur;
		cin >> cur;
		strs.push_back(cur);
	}
	vector<vector<string>> result = groupAnagrams(strs);
	for(auto node : result) {
		for(auto str : node) {
			cout << str << " ";
		}
		cout << endl;
 	}
	return 0;
}