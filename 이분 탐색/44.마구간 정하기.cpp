#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> xi;

int CntHorse(int s,int c){
	int i, start=xi[0], cnt=1;
	for(i=1;i<xi.size();i++){
		if(xi[i]-start>=s){
			cnt++;
			start=xi[i];
		}

	}	
	return cnt;
}
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n, c, i, a;
	int lt=1, rt, mid, cnt=0, res;

	scanf("%d %d",&n, &c);
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		xi.push_back(a);
	}
	
	sort(xi.begin(),xi.end());
	rt=xi[n-1];
	
	while(lt<=rt){
		mid=(lt+rt)/2;
		cnt=CntHorse(mid,c);
		if(cnt<c){
			rt=mid-1;	
		}
		else{
			lt=mid+1;
			res=mid;
		}
	}
	
	printf("%d",res);
	
	return 0;
}

