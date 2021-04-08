#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	int i, cnt=0;
	string str;
	while(true){
		cin>>str;
		if(cin.eof()) break;
		cnt++;
	}
	cout<<cnt;
		
	return 0;
}
