class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (isFound(board, word.c_str(), i, j, m, n)) return true;
        	}
        }
        return false;
    }

private:
    bool isFound(vector<vector<char>>& board, const char* w, int i, int j, int m, int n) {
    	if (*w == '\0') return true;
        if (i < 0 || i >= m || j >= n || j < 0 || board[i][j] == '\0' || board[i][j] != *w) {
        	return false;
        } else {
            char tmp = board[i][j];
            board[i][j] = '\0';
            bool result =  (isFound(board, w + 1, i - 1, j, m, n) || 
            	       isFound(board, w + 1, i + 1, j, m, n) ||
            	       isFound(board, w + 1, i, j - 1, m, n) || 
            	       isFound(board, w + 1, i, j + 1, m, n));
            board[i][j] = tmp;
            return result;
        }

    }
};