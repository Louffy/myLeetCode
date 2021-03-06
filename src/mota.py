class Solution:
	def findMedian(self,A,sa,ea,B,sb,eb):
			
			while 1:
				#print A[sa:ea+1]
				#print B[sb:eb+1]
				mb=(sb+eb)/2	
				ma=(sa+ea)/2
				if sa==ma or ea==ma:
					return self.findMedianInTwo(B,sb,eb,A,sa,ea)
				if sb==mb or eb==mb:
					return self.findMedianInTwo(A,sa,ea,B,sb,eb)
				if A[ma]>=B[mb]:
					if ea-ma>mb-sb:
						ea=ea-(mb-sb)
						sb=mb
					elif ea-ma==mb-sb:
						if ea-ma==2 and (ea-sa<=4 or eb-sb<=4):
							ea=ma+1
							sb=mb-1
						else :
							ea=ma
							sb=mb
					else:
						sb=sb+(ea-ma)
						ea=ma
				
				else :
					if eb-mb>ma-sa:
						eb=eb-(ma-sa)
						sa=ma
					elif eb-mb==ma-sa:
						if eb-mb==2 and (ea-sa<=4 or eb-sb<=4):
							sa=ma-1
							eb=mb+1
						else :
							sa=ma
							eb=mb
					else :
						sa=sa+(eb-mb)
						eb=mb
	def findMedianInTwo(self,A,sa,ea,B,sb,eb):
		#print A[sa:ea+1]
	#	print B[sb:eb+1]
		if (ea-sa+1)>6:
			if (ea-sa+1)%2==1:
				ma=(sa+ea)/2
				sa=ma-2
				ea=ma+2
			else:
				ma=(sa+ea)/2
				sa=ma-1
				ea=ma+2
		c=A[sa:ea+1]+B[sb:eb+1]
		#print c
		c.sort()
		#print c
		if len(c)%2==1:
			return float(c[len(c)/2])
		else:
			return float((c[len(c)/2]+c[len(c)/2-1])/2.0)
	def findMedianSortedArrays(self,A,B):
		if len(A)<3:
			return self.findMedianInTwo(B,0,len(B)-1,A,0,len(A)-1)
		if len(B)<3:
			return self.findMedianInTwo(A,0,len(A)-1,B,0,len(B)-1)
		return self.findMedian(A,0,len(A)-1,B,0,len(B)-1)
		
o=Solution()
A=[1,5,6,7]
B=[2,3,4,8,9,10]
C=A+B
print C[len(C)/2],C[len(C)/2-1]
print o.findMedianSortedArrays(A,B)
