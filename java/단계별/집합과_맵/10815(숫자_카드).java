import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        // boolean타입은 true, false 저장 -> 성는 우수, 코테에서 사용
        // Boolean타입은 null도 저장 가능
        boolean[] arr = new boolean[20000001];

        StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(st1.nextToken());
            num += 10000000;
            arr[num] = true;
        }

        int M = Integer.parseInt(br.readLine());

        StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < M; i++) {
            int num = Integer.parseInt(st2.nextToken());
            num += 10000000;

            if (arr[num] == true) {
                bw.write("1 ");
            } else {
                bw.write("0 ");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}