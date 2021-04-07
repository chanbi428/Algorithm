#include <bits/stdc++.h>
using namespace std;

int num[246913];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int i, j, cnt=1, a;
	num[1]=-1;
	for(i=2;i<=246912;i++){
		if(num[i]==0){
			for(j=2;j*i<=246912;j++){
				num[j*i]=-1;
			}
		//	num[i]=cnt++;
		}
	}
	while(true){
		cin>>a;
		if(a==0) break;
		cnt=0;
		for(i=a+1;i<=a*2;i++){
			if(num[i]==0) cnt++;
		}
		cout<<cnt<<"\n";
	}
		
	return 0;
}
