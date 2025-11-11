#include <stdio.h>
#include <stdbool.h>
#define N 21
int arr[N];
int n,k;
int num[N];
int num_prime=0;

bool is_prime(int num){
	if (num<2) return false;
	for (int i=2; i<=(float)num/i; i++){
		if (num%i==0) return false;
	}
	return true;
}

void dfs(int x, int start){
	if (x-1+n-start+1<k) return ; //cut the branch;
	if (x>k) {
		int sum=0;
		for (int i=1; i<=k; i++){
			sum+=num[arr[i]];
		}
		if (is_prime(sum)) num_prime++;
		return ;
	}
	
	for (int i=start; i<=n; i++){
		arr[x]=i;
		dfs(x+1,i+1);//next position and next num;
		arr[x]=0;
	}
}
		  
int main(){
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++) scanf("%d", &num[i]);
	dfs(1,1);
	printf("%d",num_prime);
	return 0;
}