#include <stdio.h>



int main(){

  int x,y;
  int i,j;

  char data[9][9];

  // for make variable
  for(x=1 ; x<=9 ; x++){
    for(y=1 ; y<=9 ; y++){
      printf("(declare-const m%d%d Int)\n", x, y);
    }
  }

  // min 1 && max 9
  for(x=1 ; x<=9 ; x++){
    for(y=1 ; y<=9 ; y++){
      printf("(assert (and (>= m%d%d 1) (<= m%d%d 9)))\n", x, y, x, y);
    }
  }

  // unique row
  for(x=1 ; x<=9 ; x++){
    printf("(assert (distinct ");
    for(y=1 ; y<=9 ; y++){
      printf("m%d%d ", x, y);
    }
    printf("))\n");
  }

  // unique col
  for(y=1 ; y<=9 ; y++){
    printf("(assert (distinct ");
    for(x=1 ; x<=9 ; x++){
      printf("m%d%d ", x, y);
    }
    printf("))\n");
  }

  // printf("======>\n");


  // same group  ex) In 3*3 matrics unique number
  for(i=0 ; i<3 ; i++){

    // for(y=1 ; y<=9 ; y++){
    //   printf("m%d%d ", x, y%3 + 1);
    // }
    for(j=0 ; j<3 ; j++){
      printf("(assert (distinct ");
      for(x=1; x<=3 ; x++){
          for(y=1 ; y<=3 ; y++){
            printf("m%d%d ", x + i*3, y + j*3);
          }
      }
      printf("))\n");
    }



  }



  // get data
  // add default values!!!
  // (assert (= m15 9))

  for(i=0 ; i<9 ; i++){
    for(j=0 ; j<9 ; j++){
      scanf("%c ", &data[i][j]);
      // printf("%c ", data[i][j]);

      if(data[i][j] != '?'){
        printf("(assert (= m%d%d %c))\n", i+1, j+1, data[i][j]);
      }
    }

  }

  printf("(check-sat)\n(get-model)\n") ;

  return 0;
}
