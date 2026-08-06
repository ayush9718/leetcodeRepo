class Solution {
public:
    int prod(int n){
        string s = to_string(n);

        int prod = 1;
        for(int i =0;i<s.length(); i++){
            prod*= int(s[i]-'0');
        }
        return prod;
    }
    int smallestNumber(int n, int t) {

       for(int i=n ; i<=100; i++){
            int prod1 = prod(i);
            if(prod1%t == 0){
                return i;
            }
       }
       return -1;    
    }
};