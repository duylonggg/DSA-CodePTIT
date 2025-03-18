import java.util.Scanner;

public class DSA01012 {
    public static void genGrayCode(int N) {
        for (int i = 0; i < (1 << N); ++i) {
            int val = i ^ (i >> 1);
            String binaryStr = String.format("%" + N + "s", Integer.toBinaryString(val)).replace(' ', '0');
            System.out.print(binaryStr + " ");
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();
            genGrayCode(N); 
            System.out.println();
        }
        
        in.close();
    }
}
