class Solution {
public:
    int countOnes(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n % 2);
            n = n / 2;
        }
        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {

        unordered_map<int, vector<int>> hourMap;
        unordered_map<int, vector<int>> minuteMap;

        for (int h = 0; h < 12; h++) {
            int ones = countOnes(h);
            hourMap[ones].push_back(h);
        }

        for (int m = 0; m < 60; m++) {
            int ones = countOnes(m);
            minuteMap[ones].push_back(m);
        }

        vector<string> result;

        for (int hBits = 0; hBits <= turnedOn; hBits++) {
            int mBits = turnedOn - hBits;

            if (hourMap.count(hBits) == 0 || minuteMap.count(mBits) == 0)
                continue;

            for (int h : hourMap[hBits]) {
                for (int m : minuteMap[mBits]) {

                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    time += to_string(m);

                    result.push_back(time);
                }
            }
        }

        return result;
    }
};
