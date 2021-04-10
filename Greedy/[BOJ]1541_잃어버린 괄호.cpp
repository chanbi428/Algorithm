#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	vector<int>num;
	int a, tmp=0, i, res=0;
	char b;
	while(true){
		cin>>a>>b;
		if(cin.eof()){
			num.push_back(tmp+a);
			break;
		}
		if(b=='-'){
			num.push_back(tmp+a);
			tmp=0;
		}
		else if(b=='+'){
			tmp+=a;
		}
	}
	res=num[0];
	for(i=1;i<num.size();i++){
		res-=num[i];
	}
	cout<<res;
	
		
	return 0;
}
