import java.io.*;
import java.util.*;

public class Main
{
    public static long power(long n, long exp)
    {
        if(exp == 0) 
        {
            return 1;
        }
        long mid = power(n,exp/2);
        return (exp % 2 == 0) ? mid * mid : mid * mid * n;
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        long n = Long.parseLong(st.nextToken());
        long exp = Long.parseLong(st.nextToken());
        System.out.println(power(n,exp));
        scan.close();
    }
}
