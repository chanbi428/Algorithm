#include <stdio.h>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, asum=0, bsum=0;
	int a[10], b[10], win[10];
	
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++){
		scanf("%d",&b[i]);
	}
	
	for(i=0;i<10;i++){
		if(a[i]>b[i]){
			win[i]=1;
			asum+=3;
		}
		else if(a[i]<b[i]){
			win[i]=2;
			bsum+=3;
		}
		else{
			win[i]=0;
			asum+=1;
			bsum+=1;
		}
	}
	if(asum>bsum) printf("%d %d\nA",asum,bsum);
	else if(bsum>asum) printf("%d %d\nB",asum,bsum);
	else{
		for(i=9;i>=0;i--){
			if(win[i]==1){
				printf("%d %d\nA",asum,bsum);
				break;
			}
			else if(win[i]==2){
				printf("%d %d\nB",asum,bsum);
				break;
			}
		}
		if(i==-1) printf("%d %d\nD",asum,bsum);
	}
	
	return 0;
}

