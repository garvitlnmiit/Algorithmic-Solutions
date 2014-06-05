/*
 * Author : Garvit Sharma (garvitlnmiit)
 * Contact : garvits45 at gmail.com
 *
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;

class TestClass {

	public static void main(String[] args) throws Exception {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String test = br.readLine();
		int t = Integer.parseInt(test);
		String Num;
		int n;
		int ct;
		
		while(t>0)
		{
			ct=1;
			Num = br.readLine();
			n = Integer.parseInt(Num);
			ct=n;
			for(int i=2; i*i<=n; i++) {
			
				if(n%i==0)
					ct-=ct/i;
				while(n%i==0)
					n/=i;	
			}
			if(n>1)
			ct-=ct/n;
			
			System.out.println(""+ct);
			t--;
		}
	}
}