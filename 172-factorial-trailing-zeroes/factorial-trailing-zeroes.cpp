class Solution {
public:
    int trailingZeroes(int n) {
        int count5 = 0;
        int count2 = 0;

        for(int i=n; i>1; i--){
            int num1 = i;
            int num2 = i;
            while(num1%5==0 && num1!=0){
                count5++;
                num1 = num1/5;
            }

            while(num2%2 == 0&& num2!=0){
                count2++;
                num2 = num2/2;
            }
        }

        return min(count2,count5);
    }
};