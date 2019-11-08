#include <iostream>
using namespace std;

int main(){
	int a[]={6,2,5,5,4,5,6,3,7,6};
	int t,m_sticks=0;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		for(int i=0;i<s.length();++i){
			m_sticks+=a[s[i]-'0'];
		}
		cout<<m_sticks<<endl;
		if(m_sticks%2==1)
        {
            cout<<"7";
            m_sticks-=3;
        }
        while(m_sticks>=2)
        {
            m_sticks-=2;
            cout<<"1";
        }
        cout<<"\n";
	}
	return 0;
}