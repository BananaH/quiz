#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int A[],int n){
	if(A==NULL||n<=0)
		exit(1);
	int sum = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++)
				sum+=A[k];
			if(ans<sum)
				ans=sum;
			sum=0;
		}
		sum=0;
	}
	return ans;
}

int main()
{
	int a[9]={-2,1,-3,4,-1,2,1,-5,4};
	int b = maxSubArray(a,(int)(sizeof(a)/sizeof(a[0])));
	printf("%d\n", b);
	return 0;
}
