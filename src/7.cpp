#include<stdio.h>
class Solution {
	public:
	    int reverse(int x) {
			int rx=0;
			int temp=0;
			int c=x;
			while(x){
				temp=x%10;
				x=x/10;
				rx=rx*10+temp;
			}
		
			return rx;
		}
};
int main(){
	Solution so;
	printf("%d\n",so.reverse(2147483521));
}
