#include "libs/big_int.h"

//Найти обратное к числу (a) в кольце по модулю (m)
int main(void) {

  big_int *a = dcreate("324"); //элемент
  big_int *m = dcreate("2623"); // модуль

  big_int *r0, *r1, *r2, *q1, *x2;
  big_int *x0 = dcreate("1");
  big_int *x1 = dcreate("0");


  r0 = m;
  r1 = a;


  while(1) {

    q1 = abs_bi(division(r0,r1,&r2));
    x2 = difference2(x0, product2(x1,q1));   

    x0 = x1;
    x1 = x2;
    r0 = r1;
    r1 = r2;

    if(!compare(r2,dcreate("0")))
      break;
  }

  if (x0->sign_byte == '1')
    x0 = difference2(x0, inv_bi(m));
  

  printf("Answer: ");
  dout(x0);

  getchar();
  return(0);

}
