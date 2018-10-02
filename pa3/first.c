#include <stdio.h>


int main(){

  int x, y;
  int i, j;

  char data[8][8];







  // declare variable
  for(x=1 ; x<=8 ; x++){
    for(y=1 ; y<=8 ; y++){
      printf("(declare-const m%d%d Int)\n", x, y);
    }
  }

  // set min and max
  for(x=1 ; x<=8 ; x++){
    for(y=1 ; y<=8 ; y++){
      printf("(assert (and (<= m%d%d 1) (<= -1 m%d%d) (not (= 0 m%d%d))))\n", x, y, x, y, x, y);
    }
  }

  // get data
  for(i=0 ; i<8 ; i++){
    for(j=0 ; j<8 ; j++){
      scanf("%c ", &data[i][j]);
      // printf("%c", data[i][j]);

      if(data[i][j] == 'O'){
        // printf("find o : %d%d\n", i, j);

        printf("(assert (= m%d%d 1))\n", i+1, j+1);
      }
      else if(data[i][j] == 'X'){
        // printf("find x : %d%d\n", i, j);

        printf("(assert (= m%d%d -1))\n", i+1, j+1);
      }
    }
    // printf("\n");
  }



  // sum row is 0
  for(x=1 ; x<=8 ; x++){
    printf("(assert (= 0 (+ ");
    for(y=1 ; y<=8 ; y++){
      printf("m%d%d ",x, y);
    }
    printf(")))\n");
  }

  // sum col is 0
  for(x=1 ; x<=8 ; x++){
    printf("(assert (= 0 (+ ");
    for(y=1 ; y<=8 ; y++){
      printf("m%d%d ",y, x);
    }
    printf(")))\n");
  }



  // (assert (and (< -3 (+ a11 a21 a31)) (> 3 (+ a11 a21 a31))))


  // not continous 3 times in row
  for(x=1 ; x<=8 ; x++){
    for(y=1 ; y<=6 ; y++){
      printf("(assert (and (< -3 (+ ");
      for(i=0 ; i<3 ; i++){
        printf("m%d%d ", x, y+i);
      }
      printf(")) (> 3 (+ ");
      for(i=0 ; i<3 ; i++){
        printf("m%d%d ", x, y+i);
      }
      printf("))))\n");
    }
  }

  

  // not continous 3 times in col
  for(x=1 ; x<=8 ; x++){
    for(y=1 ; y<=6 ; y++){
      printf("(assert (and (< -3 (+ ");
      for(i=0 ; i<3 ; i++){
        printf("m%d%d ", y+i, x);
      }
      printf(")) (> 3 (+ ");
      for(i=0 ; i<3 ; i++){
        printf("m%d%d ", y+i, x);
      }
      printf("))))\n");
    }
  }



  printf("(check-sat)\n(get-model)\n") ;



  return 0;
}
