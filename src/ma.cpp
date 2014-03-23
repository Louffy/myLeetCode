//two sum
class Solution {
public:
    int maxArea(vector<int> &height) {
		int max=0,temp;
  		for(int i=0,j=height.size()-1;i<j;)
  		{
  			temp=height[j]<height[i]?height[j]:height[i];
  		  	max=(max>temp*(j-i)?max:temp*(j-i));
  			height[j]<height[i]?j--:i++;
  		}
  		return max;      
    }
};
