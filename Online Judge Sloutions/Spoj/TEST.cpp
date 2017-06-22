#include <stdio.h>
 
int main(void) {
	int a;
	scanf("%d\n",&a);
	while(a!=42)
	{
		printf("%d\n",a);
		scanf("%d\n",&a);
	}
	return 0;
} 
