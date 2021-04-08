#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	char str[100];
	vector<int> alpha(26,-1);
	cin>>str;
	for(int i=0; str[i]!='\0'; i++){
		if(alpha[str[i]-97]==-1) alpha[str[i]-97]=i;
	}
	for(int i=0;i<26;i++){
		cout<<alpha[i]<<" ";
	}
		
	return 0;
}
