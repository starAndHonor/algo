public class HelloWorld {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        BigInteger m = scan.nextBigInteger();
        BigInteger[] xi= new BigInteger[100000];
        int cnt = 0;
        while(scan.hasNext()){
            xi[++cnt] = scan.nextBigInteger();
        }
    }
}