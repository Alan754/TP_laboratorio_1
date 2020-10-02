#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    int sector;
    int isEmpty;
    float salario;
    char nombre[51];
    char apellido[51];
} ePersona;

int menu();
/** \brief Se realiza el menu
 *
 */

int inicializarEmpleados(ePersona empleados[],int tam);
/** \brief inicializa las personas
 *
 * \param recibe lista
 * \param tamaño
 * \return error
 *
 */

int mostrarEmpleados(ePersona empleados[],int tam);
/** \brief muestra los empleados
 *
 * \param lista
 * \param tamanio
 * \return error
 *
 */

int mostrarEmpleado(ePersona unEmpleado);
/** \brief muestra empleados
 *
 * \param lista
 * \return error
 *
 */

int altaEmpleados(ePersona empleados[], int tam, int id);
/** \brief realiza el alta de empleados
 *
 * \param lista
 * \param tamaño
 * \param id
 * \return error
 *
 */

int buscarLibre(ePersona empleados[],int tam);
/** \brief busca espacio libre
 *
 * \param lista
 * \param tamaño
 * \return indice
 *
 */

int buscarEmpleado(ePersona empleados[], int tam, int id);
/** \brief busca empleados
 *
 * \param lista
 * \param tamaño
 * \param id
 * \return indice
 *
 */

int bajaEmpleado(ePersona empleados[],int tam);
/** \brief da de baja a un empleado
 *
 * \param lista
 * \param tamanio
 * \return error
 *
 */

int modificarEmpleado(ePersona empleados[],int tam);
/** \brief modifica al empleado
 *
 * \param lista
 * \param tamanio
 * \return error
 *
 */

int promedioEmpleados(ePersona listaEmpleado[], int tam);
/** \brief saca el promedio del salario
 *
 * \param lista
 * \param tamaño
 * \return indice
 *
 */

void ordenarEmpleadosApellido(ePersona listaEmpleado[],int cant, int criterio);
/** \brief ordena empleados
 *
 * \param lista
 * \param cantidad
 *
 */



#endif // ARRAYEMPLOYEES_H_INCLUDED
