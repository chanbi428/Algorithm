#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	vector<char>num;
	char a;
	
	while(true){
		cin>>a;
		if(cin.eof()) break;
		num.push_back(a);
	}
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i];
	}
		
	return 0;
}
