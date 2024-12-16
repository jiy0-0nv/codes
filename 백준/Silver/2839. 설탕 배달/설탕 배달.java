import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int r = 0;
		if (n%5==2) r=2;
		else if ((n%5==1)||(n%5==4)) r=1;
		
		System.out.println((r*5>n)?-1:n/5-r+(n%5+r*5)/3);
	}
}