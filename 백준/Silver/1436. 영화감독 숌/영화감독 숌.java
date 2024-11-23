import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = 666;
		while (n>1) {
			d++;
			int t = d;
			while (t>=666) {
				if (t%1000==666) {
					n--;
					break;
				}
				else t/=10;
			}
		}
		System.out.println(d);
	}
}