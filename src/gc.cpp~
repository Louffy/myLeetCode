#include<vector>
#include<iostream>
using namespace std;
class Solution{
	public:
		vector<int> grayCode(int n){
			vector<int> g;
			int s=1<<n;
			for(int i=0;i<s;i++){
				g.push_back(i^(i>>1));
				cout<<(i>>1)<<endl;
			}

			return g;
		}
};
int main()
{
	Solution so;
	vector<int> c;
	c=so.grayCode(3);
	for(int i=0;i<c.size();i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
