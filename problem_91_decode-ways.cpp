class Solution {
public:
    int numDecodings(string s) {
        const char* char_li = s.c_str();
        long size = s.size();

        if (size == 0 || char_li[0] == '0') return 0;

        int* buf = new int[size + 1];
        buf[0] = 1;
        buf[1] = 1;
        for (int i = 2; i <= size; i++) {
            int cur_digit = int(char_li[i - 1]) - 48;
            int last_digit = int(char_li[i - 2]) - 48;
            if ((last_digit == 1 && cur_digit != 0) || 
                (last_digit == 2 && cur_digit >= 1 && cur_digit <= 6)) { //11~19, 21~26
                buf[i] = buf[i - 2] + buf[i - 1];
            } else if (last_digit >= 1 && last_digit <= 2 && cur_digit == 0) { //10, 20
                buf[i] = buf[i - 2];
            } else if ((last_digit < 1 || last_digit > 2) && cur_digit == 0){ //00, 30, 40, ...
                delete buf;
                return 0;
            } else {
                buf[i] = buf[i - 1];
            }
        }
        int result = buf[size];
        delete buf;
        return result;
    }
};