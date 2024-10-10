import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int res = 0;
        
        for(int i=0;i<n;i++) {
            int num=sc.nextInt();
            if(num==1){
                continue;
            }
            double td=Math.sqrt(num);
            int t = (int)td;
            while(num%t!=0) {
                t--;
            }
            if(t==1) {
                res++;
            }
        }
        
        System.out.println(res);
        
        sc.close();
	}
}