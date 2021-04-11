#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i;
	stack<int>res;
	stack<int>ngb;
	cin>>n;
	vector<int>num(n);
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	for(i=n-1;i>=0;i--){
		while(!ngb.empty()){
			if(ngb.top()>num[i]){
				res.push(ngb.top());
				break;
			}
			else ngb.pop();
		}
		if(ngb.empty()) res.push(-1);
		ngb.push(num[i]);
	}
	for(i=0;i<n;i++){
		cout<<res.top()<<" ";
		res.pop();
	}
	
	return 0;
}
