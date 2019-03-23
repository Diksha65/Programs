import java.text.DecimalFormat;

class Knight{
    int[][] solution;
    int path = 0;

    public Knight(int N){
        solution = new int[N][N];
        for(int i=0;i<N;++i)
            for(int j=0;j<N;j++)
                solution[i][j] = 0;
    }

    public void solve(){
        if(findPath(0, 0, 0, solution.length))
            print();
        else
            System.out.println("No Path Found");
    }

    public boolean findPath(int row, int col, int index, int N){
        if(solution[row][col] != 0)
            return false;
        
        solution[row][col] = path++;
        
        if(index == N*N-1)
            return true;
        
        if(canMove(row+2, col+1, N) && findPath(row+2, col+1, index+1, N))
            return true;
        
        if(canMove(row+2, col-1, N) && findPath(row+2, col-1, index+1, N))
            return true;
        
        if(canMove(row+1, col-2, N) && findPath(row+1, col-2, index+1, N))
            return true;
        
        if(canMove(row-1, col-2, N) && findPath(row-1, col-2, index+1, N))
            return true;
        
        if(canMove(row-2, col-1, N) && findPath(row-2, col-1, index+1, N))
            return true;
        
        if(canMove(row-2, col+1, N) && findPath(row-2, col+1, index+1, N))
            return true;
        
        if(canMove(row+1, col+2, N) && findPath(row+1, col+2, index+1, N))
            return true;
        
        if(canMove(row-1, col+2, N) && findPath(row+1, col+2, index+1, N))
            return true;
        
        solution[row][col] = 0;
        path--;
        return false;
    }

    public boolean canMove(int row, int col, int N){
        return (row>=0 && col>=0 && row<N && col<N);
    }

    public void print(){
        DecimalFormat twodigits = new DecimalFormat("00");
        for(int i=0;i<solution.length;++i){
            for(int j=0;j<solution.length;++j)
                System.out.print("  " + twodigits.format(solution[i][j]));
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String args[]){
        int N = 5;
        Knight k = new Knight(N);
        k.solve();
    }
}