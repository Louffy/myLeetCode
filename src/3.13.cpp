//二分
//空间换时间，用空间存储需要重复计算的值
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   
    int maxProfit(vector<int> &prices) {
    	int max=0;
    	int h1=0;
    	vector<int> l;
    	vector<int> r;
 		l.push_back(0);
    	if(prices.size()<2)return 0; 
    	for(int i=1;i<prices.size();i++){
    		if(prices[i]-prices[h1]>max){
    			max=prices[i]-prices[h1];
    			l.push_back(max);
    		}
    		else 
    			l.push_back(max);
    		if(prices[h1]>prices[i])
    			h1=i;
    	}
    	r.push_back(0);
    	max=0;
    	h1=prices.size()-1;
    	for(int i=prices.size()-2;i>=0;i--){
    		if(prices[h1]-prices[i]>max){
    			max=prices[h1]-prices[i];
    			r.push_back(max);
    		}
    		else
    			r.push_back(max);
    		if(prices[i]>prices[h1])
    			h1=i;
    	}
    	max=0;
    	for(int i=0,j=prices.size()-1;i<prices.size(),j>=0;i++,j--)
    	{
    		if(l[i]+r[j]>max)
    			max=l[i]+r[j];
    	}	
        return max;
    }
};
int main()
{
	Solution so;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	
	cout<<so.maxProfit(a);
}
