class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5 = 0;
        int bill10 = 0;
        
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                bill5++;
            } else if (bills[i] == 10) {
                if (bill5 > 0) {
                    bill5--;
                    bill10++;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (bill10 > 0 && bill5 > 0) {
                    bill10--;
                    bill5--;
                } else if (bill5 >= 3) {
                    bill5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
