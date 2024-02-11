import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        int[][] arr1 = new int[A][B];
        int[][] arr2 = new int[A][B];

        for (int i = 0; i < A; i++) {
            StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < B; j++) {
                arr1[i][j] = Integer.parseInt(st1.nextToken());
            }
        }

        for (int i = 0; i < A; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < B; j++) {
                arr2[i][j] = Integer.parseInt(st2.nextToken());
            }
        }

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                // bw에 쓰기 위해, Integer를 문자열로 변환하기
                bw.write(Integer.toString(arr1[i][j] + arr2[i][j]));
                bw.write(" ");
            }
            bw.newLine();
        }

        br.close();
        bw.flush();
        bw.close();
    }
}