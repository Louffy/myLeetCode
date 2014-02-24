#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN -2147483648
class Solution {
	public:
	    int atoi(const char *str) {
			int flag=1;
			int space=1;
			int in=0;
			int i=0;
			if(strlen(str)==0)
				return 0;
			while(str[i]<'0'||str[i]>'9'){
				
				if(str[i]=='-'){
					flag=-1;
					i++;
					break;
				}
				if(str[i]=='+'){
					i++;
					break;
				}
				if(str[i]!=' ')
					return 0;
				i++;
			}
			int intemp=0;
			int temp=0;
			while(i<strlen(str)){
				if(str[i]<'0'||str[i]>'9')
					break;
				temp=str[i]-'0';
				if(flag==1){
					if(((INT_MAX-temp)/10.0)<in)
						return INT_MAX;
				}
				else if(flag==-1){
					if((((-INT_MIN)-temp)/10.0)<in)
						return INT_MIN;
				}
				in=in*10+temp;
				i++;
			}
			//cout<<in;
			//cout<<flag;
			if(flag==-1)
				in=-in;
			return in;
		}
};
int main(){
	Solution so;
	printf("%d\n",so.atoi("-1"));
}
