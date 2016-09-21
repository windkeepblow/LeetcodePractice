class Solution {
public:
    int numDecodings(string s) {
        const char* char_li = s.c_str();
        long size = s.size();

        if (size == 0 || char_li[0] == '0') return 0;

        int d1 = 1;
        int d2 = 1;
        for (int i = 1; i < size; i++) {
            int cur_digit = int(char_li[i]) - 48;
            int last_digit = int(char_li[i - 1]) - 48;

            if ((last_digit == 1 && cur_digit != 0) || 
                (last_digit == 2 && cur_digit >= 1 && cur_digit <= 6)) { //11~19, 21~26
                d2 = d1 + d2;
                d1 = d2 - d1;
            } else if (last_digit >= 1 && last_digit <= 2 && cur_digit == 0) { //10, 20
                d2 = d1 + d2;
                d1 = d2 - d1;
                d2 = d2 - d1;
            } else if ((last_digit < 1 || last_digit > 2) && cur_digit == 0){ //00, 30, 40, ...
                return 0;
            } else {
                d1 = d2;
            }
        }

        return d2;
    }
};