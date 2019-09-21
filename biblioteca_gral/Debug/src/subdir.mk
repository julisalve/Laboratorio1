################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Empleados.c \
../src/biblioteca_get.c \
../src/biblioteca_imprimir.c \
../src/biblioteca_ordenamientos.c \
../src/biblioteca_solicitud_datos.c \
../src/biblioteca_validaciones.c \
../src/bibliotecas_prueba.c 

OBJS += \
./src/Empleados.o \
./src/biblioteca_get.o \
./src/biblioteca_imprimir.o \
./src/biblioteca_ordenamientos.o \
./src/biblioteca_solicitud_datos.o \
./src/biblioteca_validaciones.o \
./src/bibliotecas_prueba.o 

C_DEPS += \
./src/Empleados.d \
./src/biblioteca_get.d \
./src/biblioteca_imprimir.d \
./src/biblioteca_ordenamientos.d \
./src/biblioteca_solicitud_datos.d \
./src/biblioteca_validaciones.d \
./src/bibliotecas_prueba.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


