import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        boolean flag = true;
        int answer = 0;
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        int[][] arr = new int[N][M];
        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < M; j++) {
                int input = Integer.parseInt(st1.nextToken());
                arr[i][j] = input;

                if (input == 1) {
                    q.add(new Pair(i, j));
                }
            }
        }

        while (!q.isEmpty()) {
            int r = q.peek().getFirst();
            int c = q.peek().getSecond();

            q.remove();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= N || nc >= M) {
                    continue;
                }

                if (arr[nr][nc] == 0) {
                    arr[nr][nc] = arr[r][c] + 1;
                    q.add(new Pair(nr, nc));
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0) {
                    flag = false;
                }

                answer = Math.max(answer, arr[i][j]);
            }
        }

        if (flag) {
            bw.write(Integer.toString(answer - 1));
        } else {
            bw.write("-1");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }
}