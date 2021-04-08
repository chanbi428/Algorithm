#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	char str[101];
	bool alpha[26];
	int i, j, n, cnt=0, ch;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>str;
		memset(alpha, false, sizeof(alpha));
		ch=0;
		for(j=0;str[j]!='\0';j++){
			if(str[j+1]==str[j]) continue;
			if(alpha[str[j]-97]==false) alpha[str[j]-97]=true;
			else{
				ch++;
				break;
			}
		}
		if(ch==0) cnt++;
	}
	cout<<cnt;
		
	return 0;
}
