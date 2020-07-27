#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

bool is_in_bound(int nx, int ny, int row, int col) {
    return 0 <= nx && nx < row && 0 <= ny && ny < col;
}
int solution(vector<vector<int>> board)
{
    int row = board.size();
    int col = (row > 0) ? board[0].size() : 0;
    int answer = 0;
    
    int dx[3] = {0, -1, -1};
    int dy[3] = {-1, -1, 0};
    for(int i = 0; i < row;i++) {
        for(int j = 0;j < col;j++) {
            answer = max(answer, board[i][j]);
            if (board[i][j] && i > 0 && j > 0) {
                int _min = 1002;
                for(int k = 0;k < 3;++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    _min = min(_min, board[nx][ny]);
                }
                board[i][j] = _min + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
    
    return answer * answer;
}
