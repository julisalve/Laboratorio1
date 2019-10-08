################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Avisos.c \
../src/Clientes.c \
../src/DIARIO.c \
../src/general.c 

OBJS += \
./src/Avisos.o \
./src/Clientes.o \
./src/DIARIO.o \
./src/general.o 

C_DEPS += \
./src/Avisos.d \
./src/Clientes.d \
./src/DIARIO.d \
./src/general.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


