class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	string c="";
    	if(strs.size()==0)
    		return c
        c=strs[0];
        for(int i=1;i<strs.size();i++)
        {
        	c=longTwo(c,strs[i]);
        }
        return c;
    }
    string longTwo(string a,string b)
    {
    	string c="";
    	int l=(a.length()>b.length()?b.length():a.length());
    	for(int i=0;i<l;i++)
    	{
    		if(a[i]==b[i])
    			c+=a[i];
    		else
    		 break;
    	}
    	return c;
    }
};
