#include <iostream>
using namespace std;

float Udtmasuno(float Ueni,float vel,float dt, float dx, float Uimenosfloat);

int main(){

  float vel;
  float t;
  float pasos;
  float dx; 
  float posicion;
  float dt;
  float tiempoM;
  float* lista = NULL;
  float* respuestas = NULL;

  dt=0.001;
  dx=0.001;
  pasos = 0; 
  posicion=0.0;	
  t=0;
  vel=1.0;
  lista = new float[4000];
  respuestas = new float[4000];


//rellena la lista de la funcion inicial
for(int i=0; i<4000;i++)
{
if(i<=2500)
{
lista[i]=0.5;
}

else
{
lista[i]=0;
}
}


// cambia los valores guardados en la lista para cada iteracion de tiempo
 
for(int t=0; t<700; t++)
{

for(int i=1; i<4000; i++)
{
    posicion = 2+(i*dx);
    respuestas[i]= Udtmasuno(lista[i], vel, dt, dx,lista[(i-1)]);

    cout << posicion <<" "<<lista[i];
}
cout << endl;

for(int c=1; c<4000; c++)
{
    lista[c]= respuestas[c];
}
}
  return 0;
}

float Udtmasuno(float Ueni , float vel,float dt, float dx, float Uimenos)
{
  float U;
  U= Ueni-( ( vel*(dt/dx) ) * ( Ueni - Uimenos));
  return U;
}



