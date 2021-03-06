class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0)
            return word2.size();
        if(word2.size()==0)
            return word1.size();
        int min[word1.size()+1][word2.size()+1];
        for(int i=0;i<word1.size()+1;i++)
        {
        	min[i][0]=i;
        }
        for(int i=0;i<word2.size()+1;i++)
        {
        	min[0][i]=i;
        }
        int i,j;
        for(i=1;i<word1.size()+1;i++)
        {
        	for(j=1;j<word2.size()+1;j++)
        	{
        		if(word1[i-1]==word2[j-1])
        			min[i][j]=minTre(min[i-1][j-1],min[i-1][j]+1,min[i][j-1]+1);
        		else
        			min[i][j]=minTre(min[i][j]+1,min[i-1][j]+1,min[i][j-1]+1);
        	}
        }
        return min[i-1][j-1];
    }
    int minTre(int a,int b,int c)
    {
    	return a<b?(a<c?a:c):(b<c?b:c);
    }
};
