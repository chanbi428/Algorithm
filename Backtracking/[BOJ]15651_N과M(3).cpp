#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int>res;

void seq(int num){
	if(num==m){
		for(int i=0;i<m;i++){
			cout<<res[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		res.push_back(i);
		seq(num+1);
		res.pop_back();
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	cin>>n>>m;
	seq(0);
		
	return 0;
}
