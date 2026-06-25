#include <iostream>
#include <vector>
using namespace std;
//EASY - ROTATING MATRIX CLOCKWISE BY 1
 void rotateMatrix(vector<vector<int>>& mat)
 {      
        int m = mat.size(); //Number of rows
        int n = mat[0].size(); //Number of columns
        
        int row = 0;
        int col = 0;
        
        int prev, curr;
        
        //Process one layer at a time 
        while(row < m && col < n){
            //stop if only one row @ column remains
            if(row + 1 == m || col + 1 == n)
                break;
            
            //store first element of next row
            prev = mat[row + 1][col];
           
            //Move Top Row (Left --> Right)
            for(int i = col; i<n; i++){
                curr = mat[row][i];
                mat[row][i] = prev;
                prev = curr;
            }
            row++;
            //Move Right Column (Top --> Down)
            for(int i = row; i<m; i++){
                curr =mat[i][n - 1];
                mat[i][n-1] = prev;
                prev = curr;
            }
            n--;
            //Move Bottom Row (Right --> Left)
            if(row < m){
                for(int i =n-1; i>= col; i--){
                    curr = mat[m-1][i];
                    mat[m-1][i] = prev;
                    prev = curr;
                }
            }
            m--;
            //Move Left Column (Bottom --> Top)
            if(col < n){
                for(int i = m-1; i>=row; i--){
                    curr = mat[i][col];
                    mat[i][col] = prev;
                    prev = curr;
                }
            }
            col++;
        }
    }
    
int main() {
    //creating 4x4 matrix
     vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
     };
     cout<<"Original Matrix\n";
     
     for(auto &row : mat){
         for(int val : row){
             cout<<val<<"\t";
         }
         cout<<endl;
     }
     
     //Display rotate matrix 
     rotateMatrix(mat);
     cout<<"\nMatrix After Rotation:\n";
     for(auto &row : mat){
         for(int val : row){
             cout<<val<<"\t";
         }
         cout<<endl;
     }
    return 0;
}
