import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        int c, d, e;
        
        if (a>b){
            c=a;
            d=b;
        }else{
            c=b;
            d=a;
        }
        e=c%d;
        
        while(e!=0) {
            c=d;
            d=e;
            e=c%d;
        }
        
        System.out.println(d);
        System.out.println(a*b/d);
        
        sc.close();
	}
}