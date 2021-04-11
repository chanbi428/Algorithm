#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, n, i, res;
	string str1, str2;
	cin>>t;
	while(t--){
		cin>>n;
		map<string, int> m;
		for(i=0;i<n;i++){
			cin>>str1>>str2;
			if(m.find(str2)==m.end()){
				m.insert({str2,1});
			}
			else m[str2]++;
		}
		res=1;
		for(auto j=m.begin();j!=m.end();j++) res*=j->second+1;
		cout<<res-1<<"\n";
	}
	
	return 0;
}
