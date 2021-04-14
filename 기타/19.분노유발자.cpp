#include <stdio.h>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, cnt=0, max=0;
	int arr[100];
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	max=arr[n-1];
	
	for(i=n-2;i>=0;i--){
		if(max<arr[i]){
			cnt++;
			max=arr[i];
		}
	}
	
	printf("%d",cnt);
	
	return 0;
}

