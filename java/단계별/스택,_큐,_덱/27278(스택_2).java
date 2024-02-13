import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        Stack<Integer> S = new Stack<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            int input = Integer.parseInt(st.nextToken());

            switch (input) {
                case 1:
                    int num = Integer.parseInt(st.nextToken());
                    S.push(num);
                    break;
                case 2:
                    if (S.empty()) {
                        bw.write("-1\n");
                    } else {
                        // java에서는 pop()하면 최상단 값이 튀어나온다.
                        bw.write(Integer.toString(S.pop()) + '\n');
                    }
                    break;
                case 3:
                    bw.write(Integer.toString(S.size()) + '\n');
                    break;
                case 4:
                    if (S.empty()) {
                        bw.write("1\n");
                    } else {
                        bw.write("0\n");
                    }
                    break;
                case 5:
                    if (S.empty()) {
                        bw.write("-1\n");
                    } else {
                        // S.peek() : 스택의 최상단 값 반환
                        bw.write(Integer.toString(S.peek()) + '\n');
                    }
                    break;
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}
