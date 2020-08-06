function solution(board, moves) {
    let answer = 0;
    const st = [];//바구니 스택

    for(let i=0;i<moves.length;i++){
        for(let j=0;j<board.length;j++){
            
            //인형이 존재하는 칸일 때
            if(board[j][moves[i]-1]!==0){
                if(st.length !== 0){
                    
                    //터뜨려져 사라진 인형 처리
                    if(st[st.length-1] == board[j][moves[i]-1]){
                    st.pop(); 
                    answer += 2; 
                 }else{
                     //터트려질 인형이 없을 때 
                    st.push(board[j][moves[i]-1]);
                    }
                }else st.push(board[j][moves[i]-1]);
                
                //인형뽑기한 격자 빈칸 처리
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    
    return answer;
}
