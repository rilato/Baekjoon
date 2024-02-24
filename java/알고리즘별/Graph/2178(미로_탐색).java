import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader (new InputStreamReader(System.in));

    static int N;
    static int M;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int [][] arr;
    static int [][] map;
    static boolean [][] visited;

    public static class Triple {
        int first;
        int second;
        int third;

        public Triple(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }

        public int getThird() {
            return third;
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int [N][M];
        arr = new int [N][M];
        visited = new boolean [N][M];

        for (int i = 0; i < N; i++) {
            String s = br.readLine();

            for (int j = 0; j < s.length(); j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        BFS(0, 0, 0);

        bw.write(Integer.toString(map[N - 1][M - 1]));
        br.close();
        bw.flush();
        bw.close();
    }

    public static void BFS(int row, int col, int cnt) throws IOException {
        map[row][col] = cnt + 1;
        Queue<Triple> q = new LinkedList<>();
        q.add(new Triple(row, col, cnt + 1));
        visited[row][col] = true;

        while(q.isEmpty() == false) {
            int r = q.peek().getFirst();
            int c = q.peek().getSecond();
            int cnt2 = q.peek().getThird();

            q.remove();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] == true || arr[nr][nc] == 0) {
                    continue;
                }

                map[nr][nc] = cnt2 + 1;
                q.add(new Triple(nr, nc, cnt2 + 1));
                visited[nr][nc] = true;
            }
        }
    }
}
