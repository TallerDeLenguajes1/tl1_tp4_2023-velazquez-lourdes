#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Tarea
{
    int TareaID; //Numerado en ciclo iterativo 
    char *Descripion; 
    int Duracion; // entre 10 - 100
}Tarea; 

void CargarTarea(Tarea ** lista, int Cant);
void moverTarea(Tarea ** lista1, Tarea ** lista2, int Cant);
void mostrarTarea(Tarea **lista, int Cant);
void inicial (Tarea **lista, int Cant);

int main()
{
    int canTarea=0;
    printf("Ingrese la cantidad de taraeas:");
    scanf("%d", &canTarea);
    Tarea **listaTarea = (Tarea**)malloc((canTarea)*sizeof(Tarea*));
    Tarea **listaTareaRealizadas = (Tarea**)malloc((canTarea)*sizeof(Tarea*));
    inicial(listaTarea, canTarea);
    inicial(listaTareaRealizadas, canTarea);
    CargarTarea(listaTarea, canTarea);
    mostrarTarea(listaTarea, canTarea);
    moverTarea(listaTarea, listaTareaRealizadas, canTarea);
    mostrarTarea(listaTareaRealizadas, canTarea);
  
}
void CargarTarea(Tarea ** lista, int Cant)
{
    char descrip [200];
    int durac;
    for (int i = 0; i < Cant; i++)
    {
        lista[i]= (Tarea*)malloc((sizeof(Tarea*)));
        lista[i]->TareaID=i;
        printf("duracion: ");
        scanf("%d", &durac);
        fflush(stdin);
        printf("Descripcion:");
        gets(descrip);
        fflush(stdin);
        lista[i]->Descripion=(char*)malloc(sizeof(char)*strlen(descrip));
        strcpy(lista[i]->Descripion, descrip);
        lista[i]->Duracion=durac;
    }
}

void mostrarTarea(Tarea **lista, int Cant)
{
    printf("Lista: \n");
    for (int i = 0; i < Cant; i++)
    {
        printf("Tarea N°: %d \n", lista[i]->TareaID);
        printf("Duracion: %d \n", lista[i]->Duracion);
        printf("Descripcion: %s \n", lista[i]->Descripion);
    }
    
}

void moverTarea(Tarea ** lista1, Tarea ** lista2, int Cant)
{
    int respuesta;
    for (int i = 0; i < Cant; i++)
    {
        printf("la tarea %d esta realizada ? \n", lista1[i]->TareaID);
        scanf("%d", &respuesta);
        fflush(stdin);
        lista2[i]= (Tarea*)malloc((sizeof(Tarea*)));
        if (respuesta == 1)
        {
            lista2[i]=lista1[i]; 
            lista1[i] = NULL;
        }
        else
        {
            lista2[i] = NULL;
        }
        
    }
    
}

void inicial (Tarea **lista, int Cant)
{
    for (int i = 0; i < Cant; i++)
    {
        lista[i]= NULL;
    }
    
} 
