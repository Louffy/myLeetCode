class Solution:
# @return a string
	def longestPalindrome(self, s):
		sub=''
		if len(s)==0:
			return None
		m=1
		start=0
		end=0
		for i in range(0,len(s)): 
			#print s[i]
			start=i-1
			end=i+1
			mi=1
			while end<len(s):
				if s[i]==s[end]:
					end=end+1
					mi=mi+1
				else :
					break
			if start>=0:
				if s[start]==s[i]:
					start=start-1
					mi=mi+1
			while start>=0 and end<len(s):
				if s[start]==s[end]:
					mi=mi+2
					start=start-1
					end=end+1
				else:
					break
			if mi>=m:
				m=mi
				sub=s[start+1:end]
			#	print sub
		return sub
so=Solution()
print so.longestPalindrome("abadd")





