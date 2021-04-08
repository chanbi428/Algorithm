#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	int i, res=0, cnt=0, index;
	char c;
	while(true){
		cin>>c;
		if(cin.eof()) break;
		if(c>=65&&c<=90) alpha[c-65]++;
		else alpha[c-97]++;
	}
	for(i=0;i<26;i++){
		if(res<alpha[i]){
			res=alpha[i];
			index=i;
		}
	}
	for(i=0;i<26;i++){
		if(res==alpha[i]) cnt++;
	}
	if(cnt==1) cout<<(char)(index+65);
	else cout<<"?";
		
	return 0;
}
