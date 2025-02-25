import java.io.*;
import java.util.*;

class Edge
{
    int vertex;
    long value;
    public Edge(int vertex, long value)
    {
        this.vertex = vertex;
        this.value = value;
    }
}

public class Main
{
    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/11657
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++)
        {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++)
        {
            st = new StringTokenizer(scan.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            long cost = Long.parseLong(st.nextToken());
            graph.get(v1).add(new Edge(v2, cost));
        }
        long[] dist = new long[n + 1];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (Edge edge : graph.get(j))
                {
                    int v = edge.vertex;
                    long cost = edge.value;
                    if (dist[j] != Long.MAX_VALUE && dist[v] > dist[j] + cost) {
                        dist[v] = dist[j] + cost;
                        if (i == n)
                        {
                            System.out.println(-1);
                            return;
                        }
                    }
                }
            }
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 2; i <= n; i++)
        {
            ans.append(dist[i] == Long.MAX_VALUE ? -1 : dist[i]).append('\n');
        }
        System.out.println(ans);
        scan.close();
    }
}
