import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class CTDL_006 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        LinkedList<Integer> linkedList = new LinkedList<>();
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            linkedList.add(input.nextInt());
        }

        for (int i = 0; i < linkedList.size() - 1; ++i) {
            int current = linkedList.get(i);
            int j = i + 1;
            while (j < linkedList.size()) {
                int temp = linkedList.get(j);
                if (temp == current) {
                    linkedList.remove(j);
                } else {
                    ++j;    
                }
            }
        }

        for (int num : linkedList) {
            System.out.print(num + " ");
        }
        System.out.println();

        input.close();
    }
}
