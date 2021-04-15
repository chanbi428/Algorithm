#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct lecture{
	int d;
	int m;
};

bool cmp(const lecture &a, const lecture & b){
	if(a.d>b.d) return true;
	else if(a.d==b.d){
		if(a.m>b.m) return true;
	}
	return false;
}

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int n, i, day, minute, sum=0, cnt;
	lecture l;
	vector<lecture> t; 
	priority_queue<int> pQ;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&minute, &day);
		l.d=day;
		l.m=minute;
		t.push_back(l);
	}
	
	sort(t.begin(),t.end(),cmp);
	
	cnt=t[0].d;
	i=0;
	
	while(i<n){
		if(cnt==t[i].d){
			pQ.push(t[i].m);
			i++;
		}
		else{
			if(pQ.empty()==1) cnt--;
			else{
				sum+=pQ.top();
				pQ.pop();
				cnt--;
			}
		}
	}
	printf("%d",sum+pQ.top());

	return 0;
}

