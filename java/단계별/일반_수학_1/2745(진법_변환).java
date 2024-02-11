// 진법 변환을 위해 문자열을 뒤쪽에서부터 처리한다.

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int answer = 0;

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

         String N = st.nextToken();
         int B = Integer.parseInt(st.nextToken());

         for (int i = 0; i < N.length(); i++) {
             char c = N.charAt(N.length() - 1 - i); // 문자열을 뒤집어서 처리
             int now = 0;

             if (c >= 'A' && c <= 'Z') {
                 now = c - 'A' + 10;
             } else {
                 now = c - '0';
             }

             // pow는 Double로 반환하므로, int로 치환함
             int temp = (int)Math.pow(B, i);

             answer += now * temp;
         }

         bw.write(Integer.toString(answer));
         br.close();
         bw.flush();
         bw.close();
    }
}