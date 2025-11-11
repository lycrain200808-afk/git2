#include <stdio.h>
#define N 10
int st[N];
int n;

void dfs(int x){
	if (x>n) {
		for (int i=1 ; i<=n ; i++) {
			if (st[i]==1) printf("%d ",i);
		}
		printf("\n");
		return ;
	}
	
	st[x]=2;
	dfs(x+1);
	//st[x]=0;
	
	st[x]=1;
	dfs(x+1);
	//st[x]=0;
}

int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}