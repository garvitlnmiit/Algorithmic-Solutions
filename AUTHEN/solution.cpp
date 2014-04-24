#include <stdio.h>

const int N = 10010;
const int K = 110;
const int md = 1009419529;

int tt,qq,n,k,i,j,ans,t;
int last[255],f[N+K][K],g[N+K][K];
char c,s[N+K];

int main() {
  scanf("%d",&t);
  while (t--) {
    
	scanf("%d %d",&n,&k);
    scanf("%s",s+1);
    
	for (i=0;i<=n+k;i++)
      for (j=0;j<=k;j++) 
		f[i][j] = g[i][j] = 0;
    
	for (c='a';c<='z';c++) 
		last[c] = -1;
    
	f[0][0] = g[0][0] = 1;
	
    for (i=1;i<=n+k;i++) 
	{
      for (j=0; j<=k && j<=i; j++)
	  {
        f[i][j] = g[i-1][j];
        if (last[s[i]] >= i-j) {
          f[i][j] -= g[last[s[i]]-1][j-(i-last[s[i]])];

		if (f[i][j] < 0) f[i][j] += md;
        }
        g[i][j] = f[i][j];
        
		if (j > 0) 
		{
          g[i][j] += g[i-1][j-1];
		  if (g[i][j] >= md) g[i][j] -= md;
        }
      }
      last[s[i]] = i;
    }
	
    ans = md-1;
    for (i=n;i<=n+k;i++) {
      ans = ans+f[i][i-n];
      if (ans >= md) ans -= md;
    }
    printf("%d\n",ans);
  }
  return 0;
}
