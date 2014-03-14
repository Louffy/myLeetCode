class Solution {
	public:
	    bool isPalindrome(int x) {
			int y=x;
			int z=0;
			int o=10;
			int a,b;
			//溢出！！！另一种方法
			if(x<0)
				return false;
			/* while(x){
				z=z*10+x%10;
				x=x/10;
			}
			if(y==z)
				return true;
			else
				return false;
			*/
			while(x/o>=10)
				o=o*10;
			while(x>=0){
				if(x/10==0)
					return true;
				a=x/o;
				b=x%10;
				if(a!=b)
					return false;
				else{
					x=x%o;
					x=x/10;
					o=o/100;
				}
			}
			
		}
};
