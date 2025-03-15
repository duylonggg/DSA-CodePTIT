import java.util.*;

public class CTDL_001 {
    static boolean isPalindrome(String bit) {
        return bit.equals(new StringBuilder(bit).reverse().toString());
    }
    
    static void Gen(int n, String bit) {
        if (bit.length() == (n << 1)) {
            bit = bit.trim();
            if (isPalindrome(bit)) System.out.println(bit);
            return;
        }

        Gen(n, bit + "0 ");
        Gen(n, bit + "1 ");
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n;
        n = input.nextInt();

        Gen(n, "");

        input.close();
    }
}