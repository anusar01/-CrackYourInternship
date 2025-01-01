class Solution:
    def minDeletions(self, s: str) -> int:
        count_list=[0]*26
        for char in s.lower():
            if 'a'<=char<='z':
                index=ord(char)-ord('a')
                count_list[index]+=1
        count_list.sort(reverse=True)
        remove=0
        for i in range(1,26):
            while(count_list[i-1]==count_list[i] and count_list[i-1]!=0):
                count_list[i]-=1
                remove+=1
                count_list.sort(reverse=True)
        return remove

        