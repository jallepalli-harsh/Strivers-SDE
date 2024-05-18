#include<iostream>
#include<vector>

using namespace std;

class PascalTriangle{
    public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> triangle;
        for(int i = 0; i < numRows; i++){
            vector<int> row(i+1, 1); 
            for(int j = 1; j < i; j++){
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        triangle.push_back(row);
        }
        return triangle;
    }

    void prettyPrint(vector<vector<int>> pattern){
        int n = pattern.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                cout << " ";
            }
            for(int j = 0; j <= i; j++){
                cout << pattern[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    PascalTriangle pt;
    int rows;

    cout << "Enter number of rows:";
    cin >> rows;

    pt.prettyPrint(pt.generate(rows));

    return 0;
}