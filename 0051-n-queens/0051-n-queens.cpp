class Solution {
public:
    
    bool isSafe(int r , int c , int n ,vector<string>& chess){
    
        
        int row= r;
        int col =c;
        
        while(row >= 0 && col >= 0){
            
            if(chess[row][col]=='Q'){
                
                return false;
            }
            
            col--;
            row--;
        }
        
          row = r;
        col = c;
         while(row <n && col >=0 ){
            
            if(chess[row][col]=='Q'){
                
                return false;
            }
            
            row++;
            col--;
        }
        
    
    
        row = r ;
        col = c;
         while( col >= 0){
            
            if(chess[row][col]=='Q'){
                
                return false;
            }
            
         
            col--;
        }
        
            
        return true;
    }
        
      
    
    
    void solve(vector<vector<string>>& chess , vector<string> temp, int c , int n){
        
        
         if(c ==n){
            
             chess.push_back(temp);
             return;
         }
        
        
        for(int i=0;i<n;i++){
            
            if(isSafe(i,c,n,temp)){
                
                temp[i][c] = 'Q';
                solve(chess,temp,c+1,n);
                temp[i][c] ='.';
            }
            
        }
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>chess;
        vector<string> temp(n, string(n, '.'));

        solve(chess,temp,0,n);
        return chess;
    }
};