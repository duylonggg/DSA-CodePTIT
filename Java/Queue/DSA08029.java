import java.util.*;

class Matrix {
    private int[][] matrix = new int[2][3];

    public void input(Scanner in) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                this.matrix[i][j] = in.nextInt();
    }

    public Matrix rotateRight() {
        Matrix temp = new Matrix();
        temp.matrix[0][0] = this.matrix[0][0];
        temp.matrix[0][1] = this.matrix[1][1];
        temp.matrix[0][2] = this.matrix[0][1];

        temp.matrix[1][0] = this.matrix[1][0];
        temp.matrix[1][1] = this.matrix[1][2];
        temp.matrix[1][2] = this.matrix[0][2];

        return temp;
    }

    public Matrix rotateLeft() {
        Matrix temp = new Matrix();
        temp.matrix[0][0] = this.matrix[1][0];
        temp.matrix[0][1] = this.matrix[0][0];
        temp.matrix[0][2] = this.matrix[0][2];

        temp.matrix[1][0] = this.matrix[1][1];
        temp.matrix[1][1] = this.matrix[0][1];
        temp.matrix[1][2] = this.matrix[1][2];

        return temp;
    }

    public boolean compare(Matrix other) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                if (this.matrix[i][j] != other.matrix[i][j])
                    return false;
        return true;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Matrix) {
            return compare((Matrix) obj);
        }
        return false;
    }

    @Override
    public int hashCode() {
        return Arrays.deepHashCode(matrix);
    }
}

public class DSA08029 {
    static Matrix ST = new Matrix();
    static Matrix EN = new Matrix();

    public static int BFS() {
        Queue<Pair<Matrix, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(ST, 0));

        while (!q.isEmpty()) {
            Pair<Matrix, Integer> front = q.poll();
            Matrix current = front.getFirst();
            int steps = front.getSecond();

            if (current.compare(EN)) return steps;

            q.add(new Pair<>(current.rotateRight(), steps + 1));
            q.add(new Pair<>(current.rotateLeft(), steps + 1));
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        while (testCases-- > 0) {
            ST.input(in);
            EN.input(in);
            System.out.println(BFS());
        }
        in.close();
    }
}

class Pair<F, S> {
    private F first;
    private S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    public F getFirst() {
        return first;
    }

    public S getSecond() {
        return second;
    }
}
