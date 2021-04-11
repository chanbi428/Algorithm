#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, cnt=0;
	cin>>n;
	vector<int> ch(n+1);
	vector<int> num;
	for(int i=2; i<=n; i++){
		if(ch[i]==0){
			num.push_back(i);
			for(int j=2; j*i<=n; j++) ch[j*i]=1;
		}
	}
	
	int s=0, e=0, sum;
	if(!num.empty()) sum=num[0];
	while(true){
		if(e==num.size() || s>e) break;
		if(sum<n) sum+=num[++e];
		else if(sum>n) sum-=num[s++];
		else{
			cnt++;
			sum-=num[s++];
		}
	}
	cout<<cnt;
	
	return 0;
}
