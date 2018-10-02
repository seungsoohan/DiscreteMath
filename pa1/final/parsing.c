#include <stdio.h>

int main(){

  int x,y;
  int i, j;

  int data_temp;
  int value_temp;

  int data[9][9];

  scanf("sat\n(model\n");



  for(i=0 ; i<81 ; i++){
      scanf("(define-fun m%d () Int\n%d)\n", &data_temp, &value_temp);

      x = data_temp / 10;
      y = data_temp % 10;
      data[x-1][y-1] = value_temp;
  }

  for(i=0 ; i<9 ; i++){

    // if(i%3 == 0){
    //   printf("\n--------------------\n");
    // }
    // else{
    //   printf("\n");
    // }

    for(j=0 ; j<9 ; j++){
      // printf(" %d,%d  (%d)\n", i+1, j+1, data[i][j]);


      printf("%d ", data[i][j]);

    }
    printf("\n");
  }




  return 0;
}
