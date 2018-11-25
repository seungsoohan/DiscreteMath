#include <stdio.h>
#include <string.h>


int main(){

  int x,y;
  int i, j;

  int data_temp;
  int value_temp;

  int data[8][8];

  char value[100];

  char temp[100];

  scanf("sat\n(model\n");

  for(i=0 ; i<64 ; i++){
      // scanf("(define-fun m%d () Int\n%d)\n", &data_temp, &value_temp);
      // scanf("(define-fun m%d () Int\n %s", &data_temp, value);
      scanf("(define-fun m%d () Int\n", &data_temp);

      fgets(temp, 100, stdin);
      scanf("\n");


      // printf("%d,  => %s  : ", data_temp, temp);
      //
      x = data_temp / 10;
      y = data_temp % 10;
      // scanf(")\n");

      if(strcmp(temp, "1)\n")){
        // printf("one \n");
        // scanf("\n");
        data[x-1][y-1] = -1;

      }
      else{
        // printf("minus \n");
        // scanf("1))\n");
        data[x-1][y-1] = 1;

      }

      // printf("%d, %d\n", data_temp, value_temp);
      // data[x-1][y-1] = value_temp;


  }

  for(i=0 ; i<8 ; i++){
    for(j=0 ; j<8 ; j++){
      // printf(" %d,%d  (%d)\n", i+1, j+1, data[i][j]);

      if(data[i][j] == 1){
        printf("O ");
      }
      else{
        printf("X ");
      }

      // printf("%d ", data[i][j]);

    }
    printf("\n");
  }




  return 0;
}
