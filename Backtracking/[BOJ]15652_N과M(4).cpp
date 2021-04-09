#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int>res;

void seq(int num, int index){
	if(num==m){
		for(int i=0;i<m;i++){
			cout<<res[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=index;i<=n;i++){
		res.push_back(i);
		seq(num+1, i);
		res.pop_back();
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	cin>>n>>m;
	seq(0, 1);
		
	return 0;
}
