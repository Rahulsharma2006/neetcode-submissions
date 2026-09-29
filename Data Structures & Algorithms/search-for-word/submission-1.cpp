class Solution {
public:
  int n;
  int m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(dfs(0,i,j,board,word))return true; 
             }
        }
        return false;
    }
    bool dfs(int i ,int r, int c,vector<vector<char>>& board,string word ){
        if(i==word.size()){
            return true;
        }
        if(!valid(r,c) || board[r][c]!=word[i] || board[r][c]=='#')return false;
        board[r][c]='#';
         // (1) Upper Side (2) Leftside (3) DownSide (4) RightSide
        bool res = dfs(i+1,r-1,c,board,word) ||
                    dfs(i+1,r,c-1,board,word) ||
                     dfs(i+1,r+1,c,board,word) ||
                      dfs(i+1,r,c+1,board,word);
                      board[r][c]=word[i];
            return res;
    }
     bool valid(int r , int c){
        if(r<0 || r>=n || c<0 || c>=m)return false;
        return true;
     }
};
