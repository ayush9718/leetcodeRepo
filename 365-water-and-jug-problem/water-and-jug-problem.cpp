class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    bool canMeasureWater(int x, int y, int target) {
        if(x+y < target){
            return false;
        }

        return (target % gcd(x,y) == 0);
    }
};