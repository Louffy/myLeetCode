#include<string.h>
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int a[9];
        for(int i=0;i<board.size();i++)
        {
        	memset(a,0,9*sizeof(int));
        	for(int j=0;j<board[i].size();j++)
        	{
        		if(board[i][j]!='.')
        		{
        			if(a[board[i][j]-'1']==1)
        				return false;
        			else a[board[i][j]-'1']=1;
        		}
        	}
        }
        for(int j=0;j<board.size();j++)
        {
        	memset(a,0,9*sizeof(int));
        	for(int i=0;i<board[i].size();i++)
        	{
        		if(board[i][j]!='.')
        		{
        			if(a[board[i][j]-'1']==1)
        				return false;
        			else a[board[i][j]-'1']=1;
        		}
        	}
        }
        for(int j=0;j<board.size();j+=3)
        {
        	for(int i=0;i<board[i].size();i+=3)
        	{
        		memset(a,0,9*sizeof(int));
        		for(int k=0;k<3;k++)
        		{
        			for(int s=0;s<3;s++)
        			{
        				if(board[j+k][i+s]!='.')
        				{
        					if(a[board[j+k][i+s]-'1']==1)
        						return false;
        					else a[board[j+k][i+s]-'1']=1;
        				}
        			}
        		}
        	}
        }
        return true;
    }
};

