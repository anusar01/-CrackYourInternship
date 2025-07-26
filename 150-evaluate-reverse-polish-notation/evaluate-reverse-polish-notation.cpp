class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++){
            
                if(tokens[i]=="+"){
                    int n2=stk.top();
                    stk.pop();
                    int n1=stk.top();
                    stk.pop();
                    int res=n1+n2;
                    stk.push(res);
                }else if(tokens[i]=="*"){
                    int n2=stk.top();
                    stk.pop();
                    int n1=stk.top();
                    stk.pop();
                    int res=n1*n2;
                    stk.push(res);
                }else if(tokens[i]=="/"){
                    int n2=stk.top();
                    stk.pop();
                    int n1=stk.top();
                    stk.pop();
                    int res=n1/n2;
                    stk.push(res);
                }else if(tokens[i]=="-"){
                    int n2=stk.top();
                    stk.pop();
                    int n1=stk.top();
                    stk.pop();
                    int res=n1-n2;
                    stk.push(res);
                }else{
                    int num=stoi(tokens[i]);
                    stk.push(num);
                }
            
        }
        return stk.top();
    }
};