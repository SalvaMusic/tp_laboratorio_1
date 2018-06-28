#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"

static int isValidNombre(char* nombre);
static int isValidHorasTrabajadas(char* strHorasTrabajadas);


Empleado* empleado_new(void)
{
    Empleado* returnAux;
    returnAux = (Empleado*) malloc(sizeof(Empleado));
    return returnAux;

}

Empleado* empleado_newParametrosString(char* id,char* strNombre,char* strHorasTrabajadas)
{
    Empleado* this = empleado_new();;

    if( !empleado_setId(this,id)        &&
        !empleado_setNombre(this,strNombre)     &&
        !empleado_setHorasTrabajadas(this,strHorasTrabajadas)
      )
    {
        return this;
    }

    empleado_delete(this);
    return NULL;
}


void empleado_delete(Empleado* this)
{
    if(this != NULL)
        free(this);
}



int empleado_setId(Empleado* this, char* strId)
{
    static int ultimoId = -1;
    int retorno = -1;
    int id;

    if(this != NULL)
    {
        retorno = 0;
        id = atoi(strId);
        if(id > 0)
        {
            this->id = id;
            if(id > ultimoId)
                ultimoId = id;
        }
        else
        {
            ultimoId++;
            this->id =  ultimoId;
        }
    }
    return retorno;
}

int empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
            retorno = 0;
            strcpy(this->nombre,nombre);
    }
    return retorno;
}

int empleado_setHorasTrabajadas(Empleado* this, char* strHorasTrabajadas)
{
    int retorno=-1;
    int horasTrabajadas;

    if(this != NULL && isValidHorasTrabajadas(strHorasTrabajadas))
    {
            retorno = 0;
            horasTrabajadas = atoi(strHorasTrabajadas);
            this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}


int empleado_getHorasTrabajadas(Empleado* this, int* horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && horasTrabajadas != NULL)
    {
            retorno = 0;
            *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}

int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL)
    {
            retorno = 0;
            strcpy(nombre,this->nombre);
    }
    return retorno;
}


static int isValidNombre(char* nombre)
{
    if(esSoloLetras(nombre))
    {
        return 1;
    }
    return 0;
}

static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    if(esNumerico(horasTrabajadas))
    {
        return 1;
    }
    return 0;
}
int empleado_trabajaMasDe120Horas(void* this)
{
    int retorno = -1;
    int horasTrabajadas;

    if (this != NULL)
    {
        retorno = 0;
        empleado_getHorasTrabajadas(this, &horasTrabajadas);
        if (horasTrabajadas > 120)
        {
            retorno = 1;
        }
    }
    return retorno;
}
