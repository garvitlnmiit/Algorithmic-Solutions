#include <stdio.h>

#define SIZE 10000
#define MD 1000000007

int main()
{
	int t, n, m, a, b, link[SIZE], count, ccc, i, mark;
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &n, &m);
		
		count=1;
		ccc=0;
		
		for(i=0; i<n; i++)
			link[i]=0;
		
		mark=1;
		
		while(m--)
		{
			scanf("%d %d", &a, &b);
			
			if(link[a]==0 && link[b]==0)
			{
				link[a]=count;
				link[b]=0-count;
				count++;
				ccc++;
			}
			else if(link[a]==0 && link[b]!=0)
			{
				link[a]=0-link[b];
			}
			else if(link[a]!=0 && link[b]==0)
			{
				link[b]=0-link[a];
			}
			else
			{
				if(link[a]==link[b])
				{
					mark=0;
				}
				else if(link[a]!=0-link[b])
				{
					int temp=link[b];
					
					for(i=0; i<n; i++)
					{
						if(link[i]==temp)
						{
							link[i]=0-link[a];
						}
						else if(link[i]==0-temp)
						{
							link[i]=link[a];
						}
					}
					ccc--;
				}	
			}
		}
		if(mark==0)
		{
			printf("NOT POSSIBLE\n");
		}
		else
		{
			int num=0;
			for(i=0; i<n; i++)
			{
				if(link[i]==0)
					num++;
			}
			
			long long int ans=1;
			for(i=0; i<num+ccc-1; i++)
			{
				if(ans*2>MD)
					ans=(ans*2)-(MD*int(ans*2/MD));
				else
					ans=ans*2;
			}
			
			if(num==n)
				ans=ans-1;

			printf("%d\n", ans);
		}	
	}
}
