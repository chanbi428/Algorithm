#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, m, i, j, score, time;
	cin>>n>>m;
	vector<int> dy(m+1);
	for(i=0;i<n;i++){
		cin>>score>>time;
		for(j=m;j>=time;j--){
			if(dy[j-time]+score>dy[j]) dy[j]=dy[j-time]+score;
		}
	}
	cout<<dy[m];
	 
	return 0;
}

