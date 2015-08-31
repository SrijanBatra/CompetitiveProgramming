#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printPowerSet(long long *set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 1; counter < pow_set_size; counter++)
    {

      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
            printf("%lld", set[j]);
       }
       printf("\n");
    }
}

int main()
{
    long long set[] = {1,2,3};
    printPowerSet(set, 3);
 
    return 0;
}


void cal_min_sum(index){
  index = index + 1;
  min_modulo = (min_modulo%(1000000000 + 7) + ((2^(n-index))*set[index])%(1000000000 + 7))%(1000000000 + 7);
}

void cal_max_sum(index){
  max_modulo = (max_modulo%(1000000000 + 7) + (2^(index))*set[index]%(1000000000 + 7))%(1000000000 + 7);
}
