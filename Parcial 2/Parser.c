#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    FILE* pFile;
    Empleado* pAuxiliarEmpleado;
    int retorno = -1;
    char bNombre[4096];
    char bHorasTrabajadas[4096];
    char bId[4096];

    pFile = fopen(fileName,"r");
    if(pFile != NULL)
    {
        retorno = 1;
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bNombre,bHorasTrabajadas);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bNombre,bHorasTrabajadas);
            pAuxiliarEmpleado = empleado_newParametrosString(bId,bNombre,bHorasTrabajadas);
            al_add(listaEmpleados,pAuxiliarEmpleado);
        }
    }
    fclose(pFile);

    return retorno;
}


