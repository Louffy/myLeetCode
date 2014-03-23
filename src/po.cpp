#include<iostream>
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> l=digits;
        int t,i;
        for(i=l.size()-1;i>=0;i--)
        {
			t=l[i]+1;
			if(t>=10)
			{
				l[i]=t%10;
			}
			else
			{
				l[i]=t;
				break;
			}
		}
		if(i==-1&&t==10)
		{
			vector<int>::iterator it=l.begin();
			l.insert(it,1);
		}
		return l;
    }
};
