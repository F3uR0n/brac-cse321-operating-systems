#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;
int s;
int *arr;
int *searchArr;

void *fibonacci(void *arg){
  arr = (int *)malloc((n + 1) * sizeof(int));
  
  if (n>=0){
    arr[0] = 0;
  }
  if (n>=1){
    arr[1] = 1;
  }
  int a1 = 0, a2 = 1;
  for (int i=2; i<=n; i++){
    int next = a1 + a2;
    arr[i] = next;
    a1 = a2;
    a2 = next;
  }
  pthread_exit(NULL);
}

void *search(void *arg) {
  for (int i = 0; i <s; i++) {
    int index = searchArr[i];
    if (index >= 0 && index <= n) {
      printf("result of search #%d = %d\n", i+1, arr[searchArr[i]]);
    }
    else{
      printf("result of search #%d = -1\n", i+1);
    }
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t p1, p2;
  printf("Enter the term of fibonacci sequence:\n");
  scanf("%d", &n);
  if (0>n || n>40){
    printf("Value Should be in this range; 0 ≤ n ≤ 40\n");
    return 0;
  }
  
  pthread_create(&p1, NULL, fibonacci, NULL);
  pthread_join(p1, NULL);

  for (int i = 0; i <=n; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  
  printf("How many numbers you are willing to search?:\n");
  scanf("%d", &s);
  if (s <= 0) {
        printf("Num of searches must be greater than 0.\n");
        free(arr);
        return 0;
  }

  searchArr = (int *)malloc(s * sizeof(int));
  for (int i = 0; i < s; i++) {
    int temp;
    printf("Enter search %d:\n", i+1);
    scanf("%d", &temp);
    searchArr[i] = temp;
  }
  pthread_create(&p2, NULL, search, NULL);
  pthread_join(p2, NULL);
  free(arr);
  free(searchArr);
}