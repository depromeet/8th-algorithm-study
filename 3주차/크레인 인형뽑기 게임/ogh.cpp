#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    vector<int> tails(board.size(), board.size());
    
    for(int i = 0 ;i < board.size();i++) {
        for(int j = 0;j < board.size();j++) {
            if (board[i][j] != 0 && tails[j] == board.size() ) {
                tails[j] = i; 
            }
        }
    }
    for(auto &x: moves) {
        if (tails[x-1] < board.size()) {
            if (!basket.empty() &&basket.top() == board[tails[x-1]][x-1]) {
                basket.pop();
                answer += 2;
            } else {
                basket.push(board[tails[x-1]][x-1]);
            }
            tails[x-1]++;
        }
    }
    return answer;
}
