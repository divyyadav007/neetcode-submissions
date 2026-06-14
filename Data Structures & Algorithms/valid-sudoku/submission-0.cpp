class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for(int r = 0 ; r < 9 ;r++){
            for(int c = 0;c<9;c++){
                char val = board[r][c];
                if(val == '.') continue;

                string rowsKey = "row" + to_string(r) + val;
                string colsKey = "cols" + to_string(c) + val;
                string boxKey = "box" + to_string((r/3)*3 + (c/3)) + val;

                if(seen.count(rowsKey) || seen.count(colsKey) || seen.count(boxKey)){
                    return false;
                }
                 seen.insert(rowsKey);
                seen.insert(colsKey);
                seen.insert(boxKey);

            }
           

            }
            return true;
    }
    };
        
        
