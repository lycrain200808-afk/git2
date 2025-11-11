#include <stdio.h>
#include <stdbool.h>
#define N 10

bool st[N];//false->unjudged;
int arr[N];
int n;

void dfs(int x){//whick num to judge
	if (x>n) {
		for (int i=1 ; i<=n ; i++) printf("%d ",arr[i]);
		printf("\n");
		return ;
	}
	
	for (int i=1 ; i<=n ; i++){
		if (!st[i]){
			st[i]=true;
			arr[i]=x;
			dfs(x+1);
			st[i]=false;			
		}
	}
}

int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}