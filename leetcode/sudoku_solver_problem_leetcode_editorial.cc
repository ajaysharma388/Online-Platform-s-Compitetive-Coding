class Solution {
public:
    
    void solveSudoku(vector<vector<char>>& board) {
      vector<int> tmp (9, 0);
      vector<vector<int>> logic_board (9, tmp);
      
      for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
          int b = (r / 3) * 3 + (c / 3);
          if (board[r][c] == '.') {
            logic_board[r][c] = 511;
          } else {
            int int_repr = 1 << (board[r][c] - '1');
            logic_board[r][c] = int_repr;
          }
        }
      }
      
      logic_board = solveSudokuLogic(logic_board);
      
      for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
          board[r][c] = int2char(logic_board[r][c]);
        }
      }
    }
  
    vector<vector<int>> solveSudokuLogic(vector<vector<int>> board) {
      vector<int> tmp (9, 0);
      vector<vector<int>> truths (3, tmp);
      int truth_count = 0;
      
      // make possibility board and truth vectors
      for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
          int x = board[r][c];
          if (!(x & (x - 1))) {
            add(truths, truth_count, r, c, x);
          }
        }
      }
      
      if (truth_count == 81) return board;
      
      //deductions
      int old_truth_count;
      do {
        old_truth_count = truth_count;

        for (int r = 0; r < 9; r++) {
          for (int c = 0; c < 9; c++) {
            if (!(board[r][c] & (board[r][c] - 1))) {
              continue;
            }
            int b = (r / 3) * 3 + (c / 3);
            int x = 511 & ~(truths[ROW][r] | truths[COL][c] | truths[BOX][b]);
            board[r][c] = x;
            if (!x) return {};
            if (!(x & (x - 1))) {
              add(truths, truth_count, r, c, x);
            }
          }
        }
      } while (old_truth_count != truth_count);
            
      if (truth_count == 81) return board;
      
      // begin recursion
      for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
          int x = board[r][c];
          if (x & (x - 1)) {
            for (int i = 1; i <= 511; i <<= 1) {
              if (x & i) {
                board[r][c] = i;
                vector<vector<int>> result = solveSudokuLogic(board);
                if(!result.empty()) {
                  return result;
                }
              }
            }
            return {};
          }
        }
      }
      return {};
    }
private:
    const int ROW = 0;
    const int COL = 1; 
    const int BOX = 2;
    void add(vector<vector<int>>& truths,
             int& truth_count,
             int r, int c, int i){
      int b = (r  /  3) *  3 + c / 3;
      truth_count++;
      truths[ROW][r] |= i;
      truths[COL][c] |= i;
      truths[BOX][b] |= i;
    }
  
    char int2char(int i) {
      for (int j = 0; j < 9; j++) {
        if (i == 1 << j) {
          return '1' + j;
        }
      }
      return  '.';
    }
};