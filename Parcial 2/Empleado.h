#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[64];
  int horasTrabajadas;
};
typedef struct S_Empleado Empleado;

Empleado* empleado_new(void);
Empleado* empleado_newParametrosString(char* id,char* strNombre,char* strHorasTrabajadas);
void empleado_delete(Empleado* this);
int empleado_setId(Empleado* this, char* id);
int empleado_getId(Empleado* this,int* id);
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_setHorasTrabajadas(Empleado* this, char* horasTrabajadas);
int empleado_getHorasTrabajadas(Empleado* this, int* horasTrabajadas);
int empleado_getNombre(Empleado* this, char* nombre);


int empleado_trabajaMasDe120Horas(void* this);

#endif // EMPLEADO_H_INCLUDED
