#include <bits/stdc++.h>
using namespace std;

struct cmp{
	bool operator()(pair<int, int>a, pair<int, int>b){
		if(a.first==b.first) return a.second>b.second;
		return a.first<b.first;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, num;
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp >heap;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		if(num==0){
			if(heap.empty()) cout<<"0\n";
			else{
				if(heap.top().second==-1) cout<<heap.top().first<<"\n";
				else cout<<-heap.top().first<<"\n";
				heap.pop();
			}
		}
		else{
			if(num>0) heap.push({-num,1});
			else heap.push({num,-1});
		}
	}

	
	return 0;
}
