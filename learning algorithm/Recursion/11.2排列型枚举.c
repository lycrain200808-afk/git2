#include <stdio.h>
#define N 21
int arr[N];
int n,r;

void dfs(int x , int start){
	if (x>r) {
		for (int i=1 ; i<=r ; i++){
			printf("%3d",arr[i]);
		}
		printf("\n");
		return ;
	}
	
	for (int i=start ; i<=n ; i++){
		arr[x]=i;
		dfs(x+1,i+1);//next position and next num;
		arr[x]=0;
	}
}
		  
int main(){
	scanf("%d %d",&n,&r);
	dfs(1,1);
	return 0;
}