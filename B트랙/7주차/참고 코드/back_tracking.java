import java.io.*;
import java.util.*;

public class Main
{
    static int n,m;
    static boolean[] visited;
    static ArrayList<Integer> ary;
    static StringBuilder ans;
    public static void dfs(int depth)
    {
        if(depth == m)
        {
            for (int i =0; i<m;++i)
            {
                ans.append(ary.get(i)).append(" ");
            }
            ans.append("\n");
            return;
        }
        for(int i =1; i<=n;++i)
        {
            if(visited[i])
            {
                continue;
            }
            visited[i] = true;
            ary.add(i);
            dfs(depth+1);
            ary.remove(ary.size() - 1);
            visited[i] = false;
        }
    }
    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/15649
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        ans = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        visited = new boolean[n+1];
        ary = new ArrayList<>();
        dfs(0);
        System.out.print(ans);
        scan.close();
    }
}
