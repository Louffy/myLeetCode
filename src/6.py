class Solution:
	# @return a string
	def convert(self, s, nRows):
		if nRows==1:
			return s
		ns=['' for i in range(0,nRows*2-2)]
		for i in range(0,len(s)):
			ni=i%(nRows*2-2)
			ns[ni]+=s[i]
		print ns
		str=''
		str+=ns[0]
		start=1
		end=len(ns)-1 
		while start<end:
			i=0
			j=0
			while i<len(ns[start]) and j<len(ns[end]):
				str+=ns[start][i]
				str+=ns[end][j]
				i+=1
				j+=1
			if i==len(ns[start]):
				str+=ns[end][j:len(ns[end])]
			else:
				str+=ns[start][i:len(ns[start])]
			start=start+1
			end=end-1
		str+=ns[start]
		return str
so=Solution()
print so.convert("ABCDEF",3)

