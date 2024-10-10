import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
  
        int m = sc.nextInt();
        int n = sc.nextInt();
        int r = 0;
        int s = 0;
        if (m==1) m++;
        while(m<=n) {
        	boolean d = true;
        	for (int i=2;i<=m/2;i++) {
        		if(m%i==0) {
        			d=false;
        			break;
        		}
        	}
        	if(d) {
        		s+=m;
        		if(r==0) r=m;
        	}
        	m++;
        }
        System.out.println((r==0)?(-1):(s+"\n"+r));
    }
}
