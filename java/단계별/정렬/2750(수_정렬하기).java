import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            arr[i] = num;
        }

        // 오름차순 정렬 방법 : Arrays.sort(배열) 사용
        // 내림차순 정렬 방법 : Arrays.sort(배열, Collections.reverseOrder()) 사용
        Arrays.sort(arr);

        for (int i = 0; i < N; i++) {
            bw.write(Integer.toString(arr[i]) + '\n');
        }

        br.close();
        bw.flush();
        bw.close();
    }
}