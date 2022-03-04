#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, n, m, i, pri, res, flag;
	
	cin>>t;
	while(t--){
		priority_queue<int>printer;
		vector<int>paper;
		cin>>n>>m;
		for(i=0;i<n;i++){
			cin>>pri;
			printer.push(pri);
			paper.push_back(pri);
		}
		res=0;
		flag=0;
		while(true){
			for(i=0;i<n;i++){
				if(printer.top()==paper[i]){
					if(i==m){
						cout<<res+1<<"\n";
						flag=1;
						break;
					}
					printer.pop();
					res++;
				}
			}
			if(flag==1) break;
		}
	}
	
	return 0;
}
