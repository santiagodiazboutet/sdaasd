#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ordenarDatos(char [][50],int [], int [], int [], float []);
int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][50], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][50], int[], int[], float[], int);
int main()
{   char nombres[3][50];
    int legajos [3];
    int nota1 [3];
    int nota2 [3];
    float promedios [3];
    int contador=0;
    int opcion=0;
    int index;
    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajos, nombres, nota1, nota2, promedios, TAM);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {
                printf("Alumno ingresado");
            }
            break;
        case 2:

        mostrarAlumnos(legajos, nombres, nota1, nota2, promedios, TAM);




break;
        }

    }
while(opcion!=9);
    /*    for(;contador<3;contador++)
        {
        printf("Ingrese el numero de legajo: ");
        scanf("%d",&legajos[contador]);
        printf("Ingrese su nombre");
        fflush(stdin);
        gets(nombres[contador]);
        printf("\nIngrese la primera nota: ");
        scanf("%d",&nota1[contador]);
        printf("\nIngrese la segunda nota: ");
        scanf("%d",&nota2[contador]);
        promedios[contador]=((float)nota1[contador]+(float)nota2[contador])/2;
        }
    */
        for(contador=0;contador<3;contador++)
        {
        printf("Para  legajo numero: %d. \n",legajos[contador]);
        printf("La primera nota es: %d.\n", nota1[contador]);
        printf("La segunda nota es: %d.\n", nota2[contador]);
        printf("El promedio es: %.2f.\n", promedios[contador]);
        printf("Su nombre es: %s", nombres[contador]);
        }
}
void ordenarDatos(char nombres[][50],int legajos[], int nota1[], int nota2[], float promedios[])
{
        int i;
        int j;
        int aux;
        float auxProm;
        char auxNombre[50];

        for(i=0;i<3;i++)
        {
            for(j=i+1;j<4;j++)
            {
                if(strcmp(nombres[i],nombres[j])>0)
                {
                    auxProm=promedios[i];
                    promedios [i]= promedios [j];
                    promedios[j]=auxProm;
                    aux=nota1[i];
                    nota1[i]= nota1[j];
                    nota1[j]=aux;
                    aux=nota2[i];
                    nota2[i]= nota2[j];
                    nota2[j]=aux;
                    aux=legajos[i];
                    legajos[i]= legajos[j];
                    legajos[j]=aux;
                    strcpy(auxNombre,nombres[i]);
                    strcpy(nombres[i],nombres[j]);
                    strcpy(nombres[j],auxNombre);
                }
            }
        }
}

int buscarLibre(int legajos, int cant)
{
    int i;
    int index=-1;
    for(i=0;i<cant;i++)
    {
        if(legajos[i]==0)
        {
            index=1;
            break;
        }
    }
    return index;
}


int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index ;
    index = buscarLibre(legajos, tam);
            if(index!=-1)
            {
                  printf("Ingrese legajo: ");
            scanf("%d", &legajos[index]);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombres[index]);

            printf("Ingrese Nota 1: ");
            scanf("%d", &nota1[index]);

            printf("Ingrese Nota 2: ");
            scanf("%d", &nota2[index]);

            promedio[index] = calcularPromedio(nota1[index], nota2[index]);
            }
            return index;
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
            {
                if(legajos[i]!=0)
                {
                    printf("%d %s %d %d %f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }

}






