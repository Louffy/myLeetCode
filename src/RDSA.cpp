#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int newLength=0;
        int currentValue;
        if(n==0)
        	return 0;
        else
        	currentValue=A[0];
        for(int i=1;i<n;i++)
        {
        	if(currentValue==A[i])
        	{
        		continue;
        	}
        	else
        	{
        		newLength++;
        		A[newLength]=A[i];
        		currentValue=A[i];
        	}
        }
        return newLength+1;
    }
};
int main()
{
	int a[]={1,2,2,3,3,4};
	Solution so;
	cout<<so.removeDuplicates(a,6)<<endl;
}