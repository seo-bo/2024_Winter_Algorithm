import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/11404
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(scan.readLine());
        int m = Integer.parseInt(st.nextToken());
        long[][] graph = new long[n+1][n+1];
        for (int i = 1; i <= n; i++)
        {
            Arrays.fill(graph[i],Long.MAX_VALUE);
            graph[i][i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            st = new StringTokenizer(scan.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            long value = Long.parseLong(st.nextToken());
            graph[v1][v2] = Math.min(graph[v1][v2], value);
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (graph[i][k] != Long.MAX_VALUE && graph[k][j] != Long.MAX_VALUE)
                    {
                        graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ans.append((graph[i][j] == Long.MAX_VALUE) ? 0 : graph[i][j]).append(' ');
            }
            ans.append('\n');
        }
        System.out.println(ans);
        scan.close();
    }
}
