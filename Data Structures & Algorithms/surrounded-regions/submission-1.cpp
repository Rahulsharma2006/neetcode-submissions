class Solution {
public:

   int x[4] ={-1,1,0,0};
  int y[4] ={0,0,-1,1};
   
    bool valid(int i , int j , int n , int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    // void dfs(int i , int j , int n , int m ,vector<vector<char>>& board){
    //     board[i][j]='#';
    //     for(int k =0;k<4;k++){
    //         int r = i+x[k];
    //         int c = j+y[k];
    //         if(valid(r,c,n,m) && board[r][c]=='O'){
    //             dfs(r,c,n,m,board);
    //         }
    //     }
    // }

    void solve(vector<vector<char>>& board) {
     int n = board.size();
     int m = board[0].size();
        queue<pair<int , int>> q;
     //First Row
     for(int j =0;j<m;j++){
        if(board[0][j]=='O'){
           q.push({0,j});
        }
     } 
     //Last Row
     for(int j =0;j<m;j++){
        if(board[n-1][j]=='O'){
            q.push({n-1,j});
        }
     }
        //First Column
        for(int i =0;i<n;i++){
        if(board[i][0]=='O'){
            q.push({i,0,});
        }
     }  
     //Last Column
     for(int i =0;i<n;i++){
        if(board[i][m-1]=='O'){
            q.push({i,m-1});
        }
     }
      while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
         board[i][j]='#';
          for(int k =0;k<4;k++){
            int r = i+x[k];
            int c = j+y[k];
            if(valid(r,c,n,m) && board[r][c]=='O'){
               q.push({r,c});
            }
        }

      }
     for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(board[i][j]=='#') board[i][j]='O';
            else if(board[i][j]=='O') board[i][j]='X';
        }
     }
    }
};
