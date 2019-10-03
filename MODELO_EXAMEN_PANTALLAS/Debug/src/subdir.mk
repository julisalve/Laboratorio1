################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MODELO_EXAMEN_PANTALLAS.c \
../src/Pantallas.c \
../src/Publicidad.c \
../src/general.c 

OBJS += \
./src/MODELO_EXAMEN_PANTALLAS.o \
./src/Pantallas.o \
./src/Publicidad.o \
./src/general.o 

C_DEPS += \
./src/MODELO_EXAMEN_PANTALLAS.d \
./src/Pantallas.d \
./src/Publicidad.d \
./src/general.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


