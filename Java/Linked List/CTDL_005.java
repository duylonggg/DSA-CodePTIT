import java.util.LinkedList;
import java.util.Scanner;

public class CTDL_005 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        LinkedList<Integer> linkedList = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            int num = input.nextInt();
            linkedList.add(num);
        }

        int removeNum = input.nextInt();
        int idx;

        while ((idx = linkedList.indexOf(removeNum)) != -1) {
            linkedList.remove(idx);
        }

        for (int num : linkedList) {
            System.out.print(num + " ");
        }
        
        input.close();
    }
}
