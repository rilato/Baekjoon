import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int M;
    static ArrayList<Integer> arr = new ArrayList<>();
    static ArrayList<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st1.nextToken());
        M = Integer.parseInt(st1.nextToken());

        StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(st2.nextToken()));
        }

        Collections.sort(arr);

        Backtracking(0, 0);

        br.close();
        bw.close();
    }

    // IOException을 throws해주어야 bw.write가 가능하다.
    public static void Backtracking(int depth, int index) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        if (depth == M) {
            for (int i = 0; i < M; i++) {
                bw.write(Integer.toString(answer.get(i))+ " ");
            }

            bw.newLine();
            bw.flush();

            return;
        }

        for (int i = index; i < N; i++) {
            answer.add(arr.get(i));
            Backtracking(depth + 1, i);
            answer.remove(answer.size() - 1); // 리스트에서 마지막 요소를 제거하여 인덱스를 유지한다. (pop_back과 동일한 역할)
        }
    }
}