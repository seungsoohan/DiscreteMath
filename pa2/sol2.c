#include <stdio.h>



int main(){


  int x, y;

  int i;
  int row_sum[8];
  int col_sum[8];

  for(i=0 ; i<8 ; i++){
    scanf("%d", &row_sum[i]);
  }

  for(i=0 ; i<8 ; i++){
    scanf("%d", &col_sum[i]);
  }

  // for(i=0 ; i<8 ; i++){
  //   printf("row => %d\n", row_sum[i]);
  //   printf("col => %d\n", col_sum[i]);
  // }

  // declare variable
  for(x=1 ; x<=8 ; x++){
    for(y=1 ; y<=8 ; y++){
      printf("(declare-const m%d%d Int)\n", x, y);
    }
  }

  // set min and max
  for(x=1 ; x<=8 ; x++){
    for(y=1 ; y<=8 ; y++){
      printf("(assert (and (>= m%d%d 0) (<= m%d%d 1)))\n", x, y, x, y);
    }
  }

  // printf("===========>\n");

  // row sum
  for(x=1 ; x<=8 ; x++){
    printf("(assert (= (+ ");
    for(y=1 ; y<=8 ; y++){
      printf("(* m%d%d %d) ", x, y, y);
    }
    printf(") %d))\n", row_sum[x-1]);
  }

  // col sum
  for(x=1 ; x<=8 ; x++){
    printf("(assert (= (+ ");
    for(y=1 ; y<=8 ; y++){
      printf("(* m%d%d %d) ", y, x, y);
    }
    printf(") %d))\n", col_sum[x-1]);
  }

  printf("(check-sat)\n(get-model)\n") ;








  return 0;
}
