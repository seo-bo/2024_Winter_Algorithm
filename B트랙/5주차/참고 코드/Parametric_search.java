import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/2805
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        int n = Integer.parseInt(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        long[] v = new long[n];
        long maxi = 0;
        st = new StringTokenizer(scan.readLine());
        for(int i =0; i<n;++i)
        {
            v[i] = Integer.parseInt(st.nextToken());
            maxi = Math.max(maxi, v[i]);
        }
        long left = 0, right = maxi, ans = 0;
        while (left <= right)
        {
            long mid = (left + right) / 2;
            long pivot = 0;
            for (int i =0; i < n; ++i)
            {
                pivot += Math.max(0,v[i] - mid);
            }
            if (pivot >= m)
            {
                left = mid + 1;
                ans = mid;
            }
            else
            {
               right = mid - 1;
            }
        }
        System.out.println(ans);
        scan.close();
    }
}
