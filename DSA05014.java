// DSA05014 - CATALAN NUMBER

// Cứ số nguyên lớn thì auto Java

import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;

class Solution{
    public void solve(Scanner sc){
        int n = sc.nextInt();
        Vector<BigInteger> dp = new Vector<>();
        for(int i = 0; i <= n; i++){
            dp.add(BigInteger.valueOf(0));
        }
        dp.set(0, BigInteger.valueOf(1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp.set(i, dp.get(i).add(dp.get(j).multiply(dp.get(i-j-1))));
            }
        }
        System.out.println(dp.get(n));
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
           Solution sol = new Solution();
           sol.solve(sc);
//            System.out.println();
        }
    }
}