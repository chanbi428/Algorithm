#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, k, i;
	queue<int>seq;
	cin>>n>>k;
	for(i=1;i<=n;i++) seq.push(i);
	cout<<"<";
	while(seq.size()!=1){
		for(i=0;i<k-1;i++){
			seq.push(seq.front());
			seq.pop();
		}
		cout<<seq.front()<<", ";
		seq.pop();
	}
	cout<<seq.front()<<">";
	
	return 0;
}
