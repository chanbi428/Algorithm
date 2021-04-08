#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	int t, r, i, j, k;
	char str[20];
	cin>>t;
	for(i=0; i<t; i++){
		cin>>r;
		cin>>str;
		for(j=0;str[j]!='\0';j++){
			for(k=0;k<r;k++){
				cout<<str[j];
			}
		}
		cout<<"\n";
	}
		
	return 0;
}
