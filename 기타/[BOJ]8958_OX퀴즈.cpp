#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, j=0, cnt=0, res=0;
	char pro[80];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pro;
		while(pro[j]!='\0'){
			if(pro[j]=='O'){
				cnt++;
				res+=cnt;
			}
			else cnt=0;
			j++;
		}
		cout<<res<<"\n";
		cnt=0;
		res=0;
		j=0;
	}
	return 0;
}
