#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

int getPI(string &str){
	vector<int>pi(str.size());
	int j=0;
	for(int i=1; i<str.size(); i++){
		while(j>0 && str[i]!=str[j]) j=pi[j-1];
		if(str[i]==str[j]) pi[i]=++j;
	}
	return pi[str.size()-1];
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	string str="";
	int L;
	char c;
	
	cin>>L;
	for(int i=0; i<L; i++){
		cin>>c;
		str+=c;
	}
	int m = getPI(str);
	cout<<L-m;
	
	return 0;
}