import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
  
        String n = sc.next();
        int b = sc.nextInt();
        long o = 0;
        
        int l = n.length();
        
        for (int i=0; i<l; i++) {
        	long p;
        	if (Character.isLetter(n.charAt(i)))
        		p = (long)(n.charAt(i)-'A'+10);
        	else
        		p = (long)(n.charAt(i)-'0');
        	for (int j=0;j<l-1-i;j++)
    			p *= b;
    		o+=p;
        }
        	
        System.out.println(o);
    }
}
