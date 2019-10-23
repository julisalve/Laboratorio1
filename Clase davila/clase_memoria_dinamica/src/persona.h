/*
 * persona.h
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
	int idPersona;
	int status;

	char nombre[51];
	int edad;
	float altura;
}Persona;


Persona* new_Persona();
Persona* new_PersonaParametros(int idPersona, int status, char* nombre, int edad, float altura);
void delete_Persona(Persona* this);
int per_setNombre(Persona* this, char *nombre); // setiar char que sea se copia y pega.
int per_getNombre(Persona* this, char *nombre); // getiar char que sea se copia y pega.
int per_setEdad(Persona* this, int edad); // setiar char que sea se copia y pega.
int per_getEdad(Persona* this, int* edad); // getiar char que sea se copia y pega.
int per_setAltura(Persona* this, float altura); // setiar char que sea se copia y pega.
int per_getAltura(Persona* this, float* altura); // getiar char que sea se copia y pega.

#endif /* PERSONA_H_ */
