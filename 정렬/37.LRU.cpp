#include <stdio.h>
#include <vector>
using namespace std;
	
int num[1001];
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int s, n, i, j, job, cnt=0;

	scanf("%d %d",&s, &n);
	vector<int> cache(s);	
	
	for(i=0;i<n;i++){
		scanf("%d", &job);
		if(num[job]==0){
			for(j=cnt;j>0;j--){
				if(cnt==s){
					num[cache[s-1]]=0;
					cnt--;
					continue;
				}
				cache[j]=cache[j-1];
			}
			num[job]=1;
			cnt++;
		}
		else{
			for(j=cnt-1;j>0;j--){
				if(cache[j]==job) break;
			}
			for(j=j;j>0;j--){
				cache[j]=cache[j-1];
			}
		}
		cache[0]=job;
		
	}
	
	
	for(i=0;i<s;i++){
		printf("%d ",cache[i]);
	}
	
	return 0;
}

