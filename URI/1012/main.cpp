#include <stdio.h>

int main() {


   double A,B,C;
   double TRANGULO,CIRCULO,TRAPEZIO,QUADRADO,RETANGULO;
   scanf("%lf",&A);
   scanf("%lf",&B);
   scanf("%lf",&C);

   TRANGULO = 1.0/2*A*C;
   CIRCULO = 3.14159*C*C;
   TRAPEZIO = C*(A+B)/2 ;
   QUADRADO = B*B;
   RETANGULO = A*B;

   printf("TRIANGULO: %.3lf\n",TRANGULO);
   printf("CIRCULO: %.3lf\n",CIRCULO);
   printf("TRAPEZIO: %.3lf\n",TRAPEZIO);
   printf("QUADRADO: %.3lf\n",QUADRADO);
   printf("RETANGULO: %.3lf\n",RETANGULO);

    return 0;
}
