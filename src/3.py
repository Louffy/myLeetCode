# coding=utf-8
class Solution:
	#DP? == find max 子段和
	def lengthOfLongestSubstring(self,s):
		str=[-1 for i in range(0,27)]
		smax=0
		start=0
		#start=head,i=end,between no repeat,smax=end-head
		for i in range(0,len(s)):
			#print s[i],i
			if str[ord(s[i])-ord('a')]==-1 or str[ord(s[i])-ord('a')]<start:
				str[ord(s[i])-ord('a')]=i
			else :	
				start=str[ord(s[i])-ord('a')]+1
				#print start
				str[ord(s[i])-ord('a')]=i
				temp=i-start+1
				if temp>smax:
					smax=temp
		temp=i-start+1
		if temp>smax:
			smax=temp
			#print s[start:i+1],temp
		return smax
	'''def lengthOfLongestSubstring(self,s):
		#print self.genSushu(ord('a'))
		#print self.genSushu(ord('z'))
		#print s
		smax=0
		index=0
		for i in range(0,len(s)):
			if (len(s)-i)<smax:
				break
			sum=1
			jmax=0
			for j in range(index,len(s)):
				term=self.genSushu(ord(s[j]))
				if sum%term != 0:
					jmax=jmax+1
					sum=sum*term
				else :
					break
			if jmax>smax:
				smax=jmax
				index=j-1
			
		print index
		print s[(index-smax):index]
		return smax
	#利用素数判断一个当前字符是否出现在前面的字符串
	def genSushu(self,c):
		sulist=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101]
		return sulist[c-ord('a')]
	'''

a=Solution()
s="qopubjguxhxdipfzwswybgfylqvjzhar"
print a.lengthOfLongestSubstring(s)
