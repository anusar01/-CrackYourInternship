class Solution:
    def decodeString(self, s: str) -> str:
        stack=[]
        currstr=""
        currnum=0
        for ch in s:
            if(ch.isdigit()):
                currnum=currnum*10+int(ch)
            elif(ch=='['):
                stack.append((currstr,currnum))
                currstr=""
                currnum=0
            elif(ch==']'):
                prevstr,repeat=stack.pop()
                currstr=prevstr+currstr*repeat
            else:
                currstr=currstr+ch
        return currstr
