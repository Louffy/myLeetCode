#include<iostream>
using namespace std;
class Solution{
public:
	void reverseWords(string &s)
	{
		if(s.size()==0)return;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')
			{
				s.erase(s.begin()-i-1);
				//cout<<s<<endl;
			}
			else
				break;
		}
		cout<<s<<endl;
		if(s.size()==0)return;
		int start=0,flag=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')
			{
				if(flag==1)
				{
					reverse(s,start,i-1);
					flag=0;
					start=i+1;
				}
				else
				{
					s.erase(s.begin()+i);
					
				}
			}
			else
			{
				flag=1;
			}
		}
	}
	void reverse(string &s,int st,int e)
	{
		char c;
		for(int i=st,j=e;i<j;i++,j--)
		{
			c=s[i];
			s[i]=s[j];
			s[j]=c;
		}
	}	
};
int main()
{
	Solution so;
	string s=" 1 sdfs  sdfsdf zfx";
	so.reverseWords(s);
	cout<<s<<endl;
}
			
				
