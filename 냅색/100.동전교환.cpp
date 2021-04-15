#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, m, i, j, weight, worth;
	cin>>n;
	vector<int> coin(n);
	for(i=0;i<n;i++){
		cin>>coin[i];
	}
	cin>>m;
	vector<int> money(m+1);
	for(i=0;i<n;i++){
		for(j=coin[i];j<=m;j++){
			if(i==0) money[j]=money[j-coin[i]]+1;
			else if(money[j-coin[i]]+1<money[j]) money[j]=money[j-coin[i]]+1;
		}
	}
	cout<<money[m];
	 
	return 0;
}

