#include "libs/big_int.h"

//Найти обратное к числу (a) в кольце по модулю (m)
int main(void) {

  big_int *a = dcreate("324"); //элемент
  big_int *m = dcreate("2623"); // модуль

  big_int *r0, *r1, *r2, *q1, *x2, *y2;
  big_int *x0 = dcreate("1");
  big_int *x1 = dcreate("0");
  big_int *y0 = dcreate("0");
  big_int *y1 = dcreate("1");

  r0 = m;
  r1 = a;


  while(1) {

    q1 = abs_bi(division(r0,r1,&r2));
    x2 = difference2(x0, product2(x1,q1));   
    y2 = difference2(y0, product2(y1,q1));

    y0 = y1;
    y1 = y2;
    x0 = x1;
    x1 = x2;
    r0 = r1;
    r1 = r2;

    if(!compare(r2,dcreate("0")))
      break;
  }

  if (y0->sign_byte == '1')
    y0 = difference2(y0, inv_bi(m));

  printf("Answer: ");
  dout(y0);

  getchar();
  return(0);

}
