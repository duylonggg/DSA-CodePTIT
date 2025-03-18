import java.util.Scanner;

public class DSA01017 {
    public static String binaryToGray(String binary) {
        StringBuilder gray = new StringBuilder();
        gray.append(binary.charAt(0));
        
        for (int i = 1; i < binary.length(); ++i) {
            char grayBit = (char) (((binary.charAt(i) - '0') ^ (binary.charAt(i - 1) - '0')) + '0');
            gray.append(grayBit);
        }
        return gray.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        while (testCases-- > 0) {
            String binary = scanner.next();
            System.out.println(binaryToGray(binary));
        }
        scanner.close();
    }
}
