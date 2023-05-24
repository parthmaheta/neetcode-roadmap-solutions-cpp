#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    bool  isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[row].size();col++)
            {  
               if(board[row][col]!='.')
               {
                   if (!isValidRow(board, row, col))
                       return false;
                   if (!isValidCol(board, row, col))
                       return false;
                   if (!isValidSubBox(board, row, col))
                       return false;
               }
            }
        }
        return true;
        
    }
    bool  isValidRow(vector<vector<char>>& board,int row,int col) {
        for(int right=col+1;right<board[row].size();right++){
            if(board[row][right]==board[row][col])
            return false;
        }
        
        return true;
    }
    bool  isValidCol(vector<vector<char>>& board,int row,int col) {
         for(int bottom=row+1;bottom<board[row].size();bottom++){
            if(board[bottom][col]==board[row][col])
             return false;
        }
        
        return true;
    }
    
    bool isValidSubBox(vector<vector<char>>& board,int row,int col) {
        for(int bottom=row+1;bottom<row+3-(row%3);bottom++){
             //check left side
             for(int left=col-col%3;left<col;left++){
                     if(board[bottom][left]==board[row][col])
                      return false;
             }
             //check right side
             for(int right=col+1;right<col+3-(col%3);right++){
                   if(board[bottom][right]==board[row][col])
                      return false;
             }
        }
        return true;
    }


};   
   

int main()
{
    Solution s;
    vector<vector<char>> v = {{'.','.','.','.','5','.','.','1','.'}, {'.','4','.','3','.','.','.','.','.'}, {'.','.','.','.','.','3','.','.','1'}, {'8','.','.','.','.','.','.','2','.'}, {'.','.','2','.','7','.','.','.','.'}, {'.','1','5','.','.','.','.','.','.'}, {'.','.','.','.','.','2','.','.','.'}, {'.','2','.','9','.','.','.','.','.'}, {'.','.','4','.','.','.','.','.','.'}};
    cout << s.isValidSudoku(v);
}