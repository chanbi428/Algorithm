#include <bits/stdc++.h>
using namespace std;

int ch[10000];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, a, i, j, sum=0, res=0, many, rank=1;
	
	cin>>n;
	vector<int>num(n);
	
	for(i=0;i<n;i++){
		cin>>a;
		num[i]=a;
		sum+=a;
		ch[4000+a]++;
	}
	sort(num.begin(),num.end());
	if(n==1) many=num[0];
	for(i=0;i<=8000;i++){
		res=max(ch[i], res);
	}
	for(i=0;i<=8000;i++){
		if(ch[i]==res && rank==1){
			rank++;
			many=i-4000;
		}
		else if(ch[i]==res && rank==2){
			many=i-4000;
			break;
		}
	}
	cout<<round((double)sum/n)<<"\n";
	cout<<num[n/2]<<"\n";
	cout<<many<<"\n";
	cout<<num[n-1]-num[0]<<"\n";
		
	return 0;
}
