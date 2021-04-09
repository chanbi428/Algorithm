#include <bits/stdc++.h>
using namespace std;
	
int DP[1002][1002];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, j;
	char str1[1002], str2[1002];
	cin>>str1>>str2;

	for(i=1;str2[i-1]!='\0';i++){
		for(j=1;str1[j-1]!='\0';j++){
			if(str2[i-1]==str1[j-1]) DP[i][j]=DP[i-1][j-1]+1;
			else DP[i][j]=max(DP[i-1][j], DP[i][j-1]);
		}
	}
	cout<<DP[i-1][j-1];
		
	return 0;
}
