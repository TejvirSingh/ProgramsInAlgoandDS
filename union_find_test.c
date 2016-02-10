#include <stdio.h>
#include <stdlib.h>

/* Made N smaller, so we can print all ids */
#define N 10



 void print_array_int(int arr[], int size)
 {
	 int i;
	 printf("  i: ");
	 for (i = 0; i < size; i++)
		 printf("%3d ", i);
	 printf("\narr: ");
	 for (i = 0; i < size; i++)
		 printf("%3d ", arr[i]);
	 printf("\n");
 }

/* returns the set id of the object. */
int find(int object, int id[])
{
  
  int next_object;
  next_object = object;

  while (next_object != id[next_object])
  {
    next_object = id[next_object];
	//printf("   %d ", next_object);
  }
  /*
  **************************************
     Changes made in the CODE
  */
  while(object != next_object)
  {
     int new_object = id[object];
     id[object] = next_object;
     object = new_object;
  }
  /*
  ***************************************
  */
  
  return next_object;
}



/* Unites the two sets specified by set_id1 and set_id2.
   ************************************************************
   
   Changes in this function... 
   
   @param a  contains the p of the input pair
   @param b  contains the q of the input pair
   
 */
void set_union(int set_id1, int set_id2, int id[], int size, int size_arr[],int a, int b)
{
  int root_node_p = find(set_id1,id); //  Asking to find the root of the node p
  int root_node_q = find(set_id2,id);  //  Asking to find the root of the node q
  if(root_node_q == root_node_p) return;

  if (size_arr[root_node_p] < size_arr[root_node_q])
  {
	id[root_node_p] = root_node_q;
	/*
	*******************************
	changes in this method.. 
	*/
	id[a] = root_node_q;
	id[b] = root_node_q;
	
	printf(" if function ... Root node of p and q",id[root_node_p],id[root_node_q]);
	/*
	*******************************
	*/
	
	size_arr[root_node_q] += size_arr[root_node_p];
  }
  else 
  	{
	   id[root_node_q] = root_node_p;
	   /*
	*******************************
	  Changes in this method...
	*/
	   id[b] = root_node_p;
	   id[a] = root_node_p;
	   printf(" else function ....  Root node of p %d and q %d and set_id1 %d and set_id2 %d ",id[root_node_p],id[root_node_q],a,b);
	   
	   /*
	*******************************
	*/
	   size_arr[root_node_p] += size_arr[root_node_q];
  	}
  

}



int main()
{
  int p, q, i, id[N], p_id, q_id, size_arr[N];
  // initialize ids and size
  for (i = 0; i < N; i++)
  {
	  id[i] = i;
	  size_arr[i] = 1;
  }

  // read pairs and keep/update connected components information
  printf("Enter pairs p q: \n");
  while (scanf("%d %d", &p, &q) == 2)
  {
    p_id = find(p, id);
    q_id = find(q, id);
    

    if (p_id == q_id)
    {
      printf(" %d and %d were on the same set\n", p, q);
	  print_array_int(id, N);
      continue;
    }

    set_union(p_id, q_id, id, N, size_arr,p,q);   // sending two extra values.. 
    printf(" %d %d link led to set union\n", p, q);
    
    print_array_int(id, N);
    print_array_int(size_arr, N);
  }
  return 0;
}
