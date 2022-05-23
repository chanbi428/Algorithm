#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, n, i, num, ver=1, flag;
	char c;
	string q;
	
	cin>>t;
	while(t--){
		deque<int>dq;
		cin>>q>>n>>c;
		flag=0;
		ver=1;
		for(i=0;i<n;i++){
			cin>>num>>c;
			dq.push_back(num);
		}
		if(n==0) cin>>c;
		for(i=0;i<q.size();i++){
			if(q[i]=='R'){
				if(ver==1) ver=2;
				else ver=1;
			}
			else{
				if(dq.empty()){
					flag=1;
					cout<<"error\n";
					break;
				}
				if(ver==1) dq.pop_front();
				else dq.pop_back();
			}
		}
		if(flag==1) continue;
		cout<<"[";
		if(!dq.empty()){
			if(ver==1){
				while(dq.size()!=1){
					cout<<dq.front()<<",";
					dq.pop_front();
				}
				cout<<dq.front();
			}
			else{
				while(dq.size()!=1){
					cout<<dq.back()<<",";
					dq.pop_back();
				}
				cout<<dq.front();
			}
		}
		cout<<"]\n";
	}
	
	return 0;
}
