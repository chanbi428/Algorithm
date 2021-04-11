#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, i, res=0, cnt, num, s;
	deque<int>dq;
	
	cin>>n>>m;
	for(i=1;i<=n;i++) dq.push_back(i);
	for(i=0;i<m;i++){
		cin>>num;
		cnt=0;
		while(dq.front()!=num){
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
		s=dq.size();
		res+=min(cnt, s-cnt);
		dq.pop_front();
	}
	cout<<res;
	
	return 0;
}
