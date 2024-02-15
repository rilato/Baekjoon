import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        int[][] arr = new int[11][4];

        arr[1][1] = 1;
        arr[2][1] = 1;
        arr[2][2] = 1;
        arr[3][1] = 2;
        arr[3][2] = 1;
        arr[3][3] = 1;

        for (int i = 4; i <= 10; i++) {
            arr[i][1] = arr[i - 1][1] + arr[i - 1][2] + arr[i - 1][3];
            arr[i][2] = arr[i - 2][1] + arr[i - 2][2] + arr[i - 2][3];
            arr[i][3] = arr[i - 3][1] + arr[i - 3][2] + arr[i - 3][3];
        }

        for (int i = 0; i < T; i++) {
            int num = Integer.parseInt(br.readLine());

            bw.write(Integer.toString(arr[num][1] + arr[num][2] + arr[num][3]) + '\n');
        }

        br.close();
        bw.flush();
        bw.close();
    }
}