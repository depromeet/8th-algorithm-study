function solution(board)
{
    let answer = 0;
    let max = 0;//정사각형의 최대 길이를 찾기 위한 변수 
    let min = 0;
     
    //board가 [[1]]인 경우 정사각형 길이를 1로 처리.
    if (board.length < 2 || board[0].length < 2) {
        for(var i = 0 ; i < board.length ; i++){
            for(var j = 0;  j < board[0].length ; j++) {
                if (board[i][j] === 1) {
                    max = 1;
                }
            }
        }
    } else {
        for(var i = 1 ; i < board.length ; i++){
            for(var j = 1;  j < board[0].length ; j++) {
              //element가 1인 경우, 왼쪽 값/왼쪽 위의 값/위의 값을 비교한 후, 그 중 가장 작은 값에 1을 더해 element에 대입.
                if(board[i][j] === 1 ){
                    min = Math.min(board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]);
                    board[i][j] = min +1;
                    
                    //최대 길이를 찾기 위해 max값 갱신.
                    if (board[i][j] > max) {
                        max = board[i][j];
                    }
                }
            }
        }
    }
    answer = max*max;
    return answer;
}
