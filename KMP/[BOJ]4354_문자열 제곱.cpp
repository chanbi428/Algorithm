#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

void getPI(vector<int> &pi, string &str2){
	int j=0;
	for(int i=1; i<str2.size(); i++){
		while(j>0 && str2[i]!=str2[j]) j=pi[j-1];
		if(str2[i]==str2[j]) pi[i]=++j;
	}
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	string str;
	
	while(true){
		getline(cin, str);
		if(str==".") break;
		int s = str.size();
		vector<int> pi(s);
		getPI(pi, str);
		int res= s-pi[s-1];
		if(s%res==0) cout<<s/res<<"\n";
		else cout<<"1\n";
	}
	
	return 0;
}