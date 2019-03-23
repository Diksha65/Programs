import java.util.Scanner;
import java.math.BigInteger;

class modifiedFibonacciDP { 
    public static void main(String args[]) throws Exception{
        Scanner scan = new Scanner(System.in);
        BigInteger fib[] = new BigInteger[3];
        int i=0;
        fib[2] = scan.nextBigInteger();
        fib[0] = scan.nextBigInteger();

        int n = scan.nextInt();
        for(; n>2; --n){
            i = (i+1) % 3;
            fib[i] = fib[(i+1) % 3].add(fib[(i+2)%3].multiply(fib[(i+2)%3]));
        }
        System.out.println(fib[i].toString());
    }
}