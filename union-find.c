#include<stdio.h>



int find(int object, int id_array[]);
void set_union(int set_id1, int set_id2, int id_array[], int size);


int main()
{
    int N= 10;
	int id[N], p,q;
	int id1,id2;
	int i;
	for(i=0;i<N;i++) id[i]=i;
    printf("Enter the values so that we can check..  ");
	
	while(scanf("%d %d",&p,&q)==2)    
	{
	id1 = find(p,id);
	id2 = find(q,id);
	
	if(id1 == id2)
	  {
	  	 printf(" The values are in the same set.. ");
	  	 
	  }
	  
	  	  set_union(id1,id2,id,N);
	  	  printf("Both the values have been brought in the same set.. ");
	  	  
	  
	  
	  for(i = 0;i<N;i++)
	  {
	  	  printf("id[%d] = %d \n",i,id[i]);
	  }
	  
	}
	  return 0;
	  

	
}

int find(int object, int id_array[])
{
	return id_array[object];
}

void set_union(int set_id1, int set_id2,int id_array[],int size)
{
	int i;
	for(i = 0;i<size;i++)
	{
		if(id_array[i]==set_id1) id_array[i]= set_id2;
	}
}


