#include <bits/stdc++.h>
using namespace std;

int n, num[20], sign[4];
int maxx=-2147000000, minn=2147000000;

void ope(int index, int sum){
	if(index==n){
		maxx=max(maxx,sum);
		minn=min(minn,sum);
		return;
	}
	for(int i=0;i<4;i++){
		if(sign[i]!=0){
			sign[i]--;
			if(i==0) ope(index+1, sum+num[index]);
			else if(i==1) ope(index+1, sum-num[index]);
			else if(i==2) ope(index+1, sum*num[index]);
			else if(i==3) ope(index+1, sum/num[index]);
			sign[i]++;
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=0;i<4;i++){
		cin>>sign[i];
	}
	ope(1, num[0]);
	cout<<maxx<<"\n"<<minn;
		
	return 0;
}
