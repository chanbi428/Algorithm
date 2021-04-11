#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int k, v, e, i, a, b, flag, j;
	cin>>k;
	
	while(k--){
		cin>>v>>e;
		vector<int>gragh[v+1];
		vector<int>ch(v+1);
		for(i=0;i<e;i++){
			cin>>a>>b;
			gragh[a].push_back(b);
			gragh[b].push_back(a);
		}
		queue<int>Q;
		for(i=1;i<=v;i++){
			if(ch[i]==0){
				Q.push(i);
				ch[i]=1;
				flag=0;
				while(!Q.empty()){
					int tmp=Q.front();
					Q.pop();
					for(j=0;j<gragh[tmp].size();j++){
						if(ch[gragh[tmp][j]]==ch[tmp]){
							flag=1;
							cout<<"NO\n";
							break;
						}
						else if(ch[gragh[tmp][j]]==0){
							Q.push(gragh[tmp][j]);
							if(ch[tmp]==1) ch[gragh[tmp][j]]=2;
							else ch[gragh[tmp][j]]=1;
						}
					}
					if(flag==1) break;
				}
				if(flag==1) break;
			}
		}
		if(flag==0) cout<<"YES\n";
	}
	
	return 0;
}
