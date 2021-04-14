#include <stdio.h>
using namespace std;

int a[52];
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	char alpa[100];
	int i,cnt=0;
	
	scanf("%s",&alpa);
	
	for(i=0;alpa[i]!='\0';i++){
		if(alpa[i]>=65&&alpa[i]<=90) a[alpa[i]-65]++;
		else a[alpa[i]-71]++;	
	}

	scanf("%s",&alpa);
	
	for(i=0;alpa[i]!='\0';i++){
		if(alpa[i]>=65&&alpa[i]<=90){
			a[alpa[i]-65]--;
			if(a[alpa[i]-65]<0){
				printf("NO");
				cnt=1;
				break;
			}
		}
		else{
			a[alpa[i]-71]--;
			if(a[alpa[i]-71]<0){
				printf("NO");
				cnt=1;
				break;
			}
		}
	}
	if(cnt==0) printf("YES");
	
	return 0;
}

