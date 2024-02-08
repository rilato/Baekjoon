import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));

        int cnt = 0;

        // N 입력 받기
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int [N];

        // N개의 값 입력 받기
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        // v 입력 받기
        int v = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            if (v == arr[i]) {
                cnt++;
            }
        }

        // BufferedWriter의 write() 메서드는 정수 값을 출력하는 것이 아니라, 문자열을 출력한다.
        // 따라서 cnt를 문자열로 변환해야 한다.
        bw.write(Integer.toString(cnt));
        br.close();
        bw.flush();
        bw.close();
    }
}