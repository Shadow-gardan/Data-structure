#include<stdio.h>
int fun(int a){
	fun(a-1);
	printf("%d\n",a);
}

int main(){
	int c = 4;
	fun(c);
	return 0;
	
}

