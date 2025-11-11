#include <stdio.h>
typedef struct{
	float realpart;
	float imagepart;
}Complex;

void Create( Complex *c , float x , float y){
	c-> realpart=x;
	c-> imagepart=y;
}

float Getreal(Complex c){
	return c.realpart;
}

float Getimage(Complex c){
	return c.imagepart;
}

Complex add(Complex c1 , Complex c2){
	Complex sum;
	sum.realpart=c1.realpart+c2.realpart;
	sum.imagepart=c2.imagepart+c1.imagepart;
	return sum;
}
Complex sub(Complex c1 , Complex c2){
	Complex difference;
	difference.imagepart=c1.imagepart-c2.imagepart;
	difference.realpart=c1.realpart-c2.realpart;
	return difference;
}
Complex multi(Complex c1 , Complex c2){
	Complex product;
	product.realpart=c1.realpart*c2.realpart-c1.imagepart*c2.imagepart;
	product.imagepart=c1.realpart*c2.imagepart+c1.imagepart*c2.realpart;
	return product;
}
Complex divide(Complex c1 , Complex c2){
	Complex q;
	q.realpart=(c1.realpart*c2.realpart+c1.imagepart*c2.imagepart)/(c2.realpart*c2.realpart+c2.imagepart*c2.imagepart);
	q.imagepart=(c1.imagepart*c2.realpart-c1.realpart*c2.imagepart)/(c2.realpart*c2.realpart+c2.imagepart*c2.imagepart);
	return q;
}

int main(){
	Complex numerator,denominator,z,c1,c2;
	int x=8,y=6;
	int a=4,b=3;
	Create( &c1 , x , y);
	Create( &c2 , a , b);
	numerator=multi( c1 , c2);
	denominator=add( c1 , c2);
	z=divide(numerator , denominator);
	printf("z=%f+%fi",z.realpart,z.imagepart);
	return 0;
}