#include <stdio.h>

// Toma un array y su tamaño. Retorna el elemento max.
// (int[], int) => int
int arr_max(int arr[], int size) {
  
  int max = arr[0];

  for(int n = 1; n < size; n++) {
    
    if(arr[0] < arr[n]){

      int rest[size-n];
      
      for(int i=0; i < (size-n); i++){
        rest[i] = arr[n+i];
      }

      /*debug
      printf("%d %c %d %c", arr[0], '<', arr[n], '\n');
      printf("%s", "arr\n");
      for(int i=0; i < (size-n); i++){
        printf("%d", rest[i]);
        printf("%c",'\n');
      }
      printf("%s","end\n"); */
      
      max = arr_max(rest, size-n);
      
      break;
    }
  }

  return max;
}

// Lo siguiente es para Functions in C de Hacker rank
int max_of_four(int a, int b, int c, int d) {

  int nums[4] = {a, b, c, d};
  int max_of_nums = arr_max(nums, 4);
  
  return max_of_nums;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}