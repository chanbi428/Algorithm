#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int n, i, car, cnt=1;
	stack<int> cross;
	vector<char> res;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&car);
		res.push_back('P');
		cross.push(car);
		while(cross.empty()!=1&&cnt==cross.top()){
			res.push_back('O');
			cross.pop();
			cnt++;
		}
	}
	if(cross.empty()==0) printf("impossible");
	else{
		for(i=0;i<2*n;i++){
			printf("%c",res[i]);
		}
	}
	
	return 0;
}

