#include <stdio.h>
using namespace std;

int num[10];

int main(int argc, char** argv) {
	//freopen("input.txt", "rt", stdin);

	char arr[100];
	int i,max=0,index;
	
	scanf("%s",&arr);
	
	for(i=0;arr[i]!='\0';i++){
		num[arr[i]-48]++;
	}
	for(i=1;i<10;i++){
		if(max<=num[i]){
			max=num[i];
			index=i;
		}
	}

	printf("%d",index);
	
	return 0;
}

