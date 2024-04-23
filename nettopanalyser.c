//Snehal Shelke

#include<stdio.h>
#include<stdlib.h>
// Network Topology Analyser
// following topologies can be detected by the code
// 1) mesh 2) star 3)unidirectional ring 4)hybrid
int main(){
	int n ;
	printf("no of systems\n");
	scanf("%d",&n);
	int i=0;
	int **t=(int *)malloc(sizeof(int)*n);
	int j=0;
	int cnt=0;
	int flg=0;
	int R=0;
//taking input for Matrix 
//Matrix consist info about N*N  matrix which are in a network
//put 0 if not connected to particular node
//input 1 if connected to particular node 
	while(i<n){
		printf("row %d \n",i+1);
		t[i]=(int *)malloc(sizeof(int)*n);
		while(j<n){
			printf("%d->",j+1);
			if(i!=j){
				//	printf("%d->",j+1);
					scanf("%d",&t[i][j]);
					if(t[i][j]==1){
						cnt=cnt+1;
					}
				}
			else{
					
			       	t[i][j]=0;
				printf("%d\n",t[i][j]);	
			}
			j=j+1;
			}
		R=R+cnt;
		cnt=0;
		j=0;
		i++;
	}
//mesh topology = all systems are connected to every other system in network =>total no. of connections will ne n*n-n ( subtracting
//n since nodes connected to itself is 0 )


	if(R==(n*n)-n){
		printf("mesh topology\n");
	}
//ring topology = all systems are connected to one other system in unidirectional way in a network =>total no. of connections will ne n 
	else if(R==n){
		i=0;
		j=0;
		int flg=0;
		while(i<n){
			if(t[i][j]==1){
				cnt=cnt+1;
			}
			j=j+1;
			if(j==n){
				j=0;
				i=i+1;
				if(cnt!=1){
						printf("hybrid\n");
						return 1;
				}
				cnt=0;
			}

			}
			i=0;j=0;
			while(j<n){
				if(t[i][j]==1){
					cnt=cnt+1;
				}	
				i=i+1;
					if(i==n){
						i=0;
						j=j+1;
					if(cnt!=1){
							printf("hybrid\n");
							return 1;
						}
				cnt=0;
			}

			}

		printf("ring topology\n");
	}
	else if(R==2 && n==2){
		printf("point to point topology\n");
	}
///star topology = all systems are connected to one system(HUB) in a network and Hub too can send msg to all other system
//  no. of connections will ne n*2-2
	else if(R==(n*2)-2){
			i=0;
			j=0;
			while(i<n){
			if(t[i][j]==1){
				cnt=cnt+1;
			}
			j=j+1;
			if(j==n){
				j=0;
				i=i+1;
				if(cnt!=1 && cnt!=(n-1)){
						printf("hybrid\n");
						return 1;
				}
				cnt=0;
			}

			}
			i=0;j=0;
			while(j<n){
				if(t[i][j]==1){
					cnt=cnt+1;
				}	
				i=i+1;
					if(i==n){
						i=0;
						j=j+1;
						if(cnt!=1 && cnt!=(n-1)){
							printf("hybrid\n");
							return 1;
						}
				cnt=0;
			}

			}

		printf("Star Topology\n");
	}
// no connections 
	else if(R==0){
			printf("no connection");
		}	
	else{
	
			printf("hybrid topology\n");
			printf("or all systems are not connected");
	}

	return 0;
}


