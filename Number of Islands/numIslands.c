#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int rank[10],parent[100];
int a[100][100];

int find(int parent[],int x){
	if(parent[x]!=x){
		parent[x]=find(parent,parent[x]);
	}
	return parent[x];
}
void Union(int parent[],int x,int y){
	
	int xRoot=find(parent,x);
	int yRoot=find(parent,y);
	if(xRoot==yRoot)
		return;
	if(rank[xRoot]<rank[yRoot])
		parent[xRoot]=yRoot;
	else if(rank[xRoot]>rank[yRoot])
		parent[yRoot]=xRoot;
	else{
		parent[yRoot]=xRoot;
		rank[xRoot]=rank[xRoot]+1;
	}
}

int countIslands(int n,int m)
{	
	int k=0;
	for(int j=0;j<n;j++){
		for(k=0;k<m;k++){
			if(a[j][k]==0)
				continue;
			if(j+1<n && a[j+1][k]==1){
				Union(parent,((j*m)+k),((j+1)*m)+k);
			}
			if(j-1>=0 && a[j-1][k]==1){
				Union(parent,((j*m)+k),((j-1)*m)+k);
			}
			if(k+1<m && a[j][k+1]==1){
				Union(parent,((j*m)+k),(j*m)+k+1);
			}
			if(k-1>=0 && a[j][k-1]==1){
				Union(parent,((j*m)+k),(j*m)+k-1);
			}
			if(j+1<n && k+1<m && a[j+1][k+1]==1){
				Union(parent,((j*m)+k),((j+1)*m)+k+1);
			}
			if(j+1<n && k-1>=0 && a[j+1][k-1]==1){
				Union(parent,((j*m)+k),((j+1)*m)+k-1);
			}
			if(j-1>=0 && k+1<m && a[j-1][k+1]==1){
				Union(parent,((j*m)+k),((j-1)*m)+k+1);
			}
			if(j-1>=0 && k-1>=0 && a[j-1][k-1]==1){
				Union(parent,((j*m)+k),((j-1)*m)+k-1);
			}
		}
	}
	int c[n*m],numberOfIslands=0;
	//memset(c,0,n*m);
	for(int i=0;i<n*m;i++){
		c[i]=0;
	}
	
	for(int j=0;j<n;j++){
		for(int k=0;k<m;k++){
			if(a[j][k]==1){
				int x=find(parent,(j*m)+k);
				//printf("%d \n",x);
				if(c[x]==0){
					numberOfIslands++;
					c[x]++;
				}else{
					c[x]++;
				}
			}
		}
	}
	return numberOfIslands;
}

int main(void)
{
	//int a[100][100];                     
	int i,j,n,m;
	printf("Enter row and columns\n");
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n*m;i++){
		parent[i]=i;
	}
	printf("enter the elements: \n");  //entering elements
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//printf("elements at [%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	
	printf("Number of islands is: %d\n",countIslands(n,m));

}
