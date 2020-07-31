function solution(s) {
   let answer = s; 

    for (let i = 1; i <= s.length/2; i++) 
    {
        let comStr = ""; //압축한 문자열 저장하는 변수
        let curStr = s.slice(0, i); //맨 처음부터 i번째 문자열까지를 저장하는 변수 
        let count = 1; //압축 횟수를 저장하는 변수

        for (let j = i; j < s.length; j += i) //i(비교할 문자열 길이)만큼 증가
        {
            const newStr = s.slice(j, j+i);
            if (curStr == newStr) 
            //예시) aabbaccc => i가 1일때 curStr: a(첫번째) newStr: a(두번째)
            //문자열 압축이 되는 경우
            {
                count++; 
            }
            else //문자열 압축이 되지 않을 경우
            {
                comStr += (count > 1 ? count + curStr : curStr); 
                //예시) aabbaccc => i가 1일 때, count가 1보다 크면 comStr = 2a
                curStr = newStr; //현재 문자열을 새로 비교한 문자열로 대체 
                count = 1; // 초기화
            }
        }

            //마지막 문자 처리 
            comStr += (count > 1 ? count + curStr : curStr);

        //가장 짧은 문자열의 길이를 찾는 과정
        if (answer.length > comStr.length)
        {
            answer = comStr;
        }
    }

    return answer.length;
}
