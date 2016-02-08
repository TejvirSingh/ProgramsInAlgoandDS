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
  next_object = id[object];

  //printf("\nFind root of %d\n\t", object);
  //printf("   %d ", next_object);
  while (next_object != id[next_object])
  {
    next_object = id[next_object];
	//printf("   %d ", next_object);
  }

  return next_object;
}

/* The following function has been added to make the program work as
   a full path compression with the weighted quick union

*/
int _find_root(int find_root_for_id,int id_arr[])
{
    // Variable created for the for loop..
    int i;

    //for loop begins here
    /*
        @param: find_root_for_id is the variable used to store the object for which
        we are trying to find the root.
        @param : id_arr[] is the array containing the objects.

    */
    for(i=0;find_root_for_id != id_arr[find_root_for_id];i++)
    {
        id_arr[find_root_for_id] = id_arr[id_arr[find_root_for_id]];
        i = id_arr[find_root_for_id];
    }

    // value returned is the root for the object..  
    return find_root_for_id;
}

/* Unites the two sets specified by set_id1 and set_id2.
 */
void set_union(int set_id1, int set_id2, int id[], int size, int size_arr[])
{
  int _id1 = _find_root(set_id1,id);
  int _id2 = _find_root(set_id2,id);
  if (size_arr[_id1] < size_arr[_id2])
  {
	id[_id1] = _id2;
	size_arr[_id2] = size_arr[_id1]  + size_arr[_id2];
  }
  else
  {
	id[_id2] = _id1;
	size_arr[_id1] = size_arr[_id1]  + size_arr[_id2];
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

    set_union(p_id, q_id, id, N, size_arr);
    printf(" %d %d link led to set union\n", p, q);
    print_array_int(id, N);
    print_array_int(size_arr, N);
  }
printf("Please enter the last pair \n");
scanf("%d %d\n",&p,&q);

}
