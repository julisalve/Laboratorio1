################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CLIENTES.c \
../src/MODELO.c \
../src/PEDIDOS.c 

OBJS += \
./src/CLIENTES.o \
./src/MODELO.o \
./src/PEDIDOS.o 

C_DEPS += \
./src/CLIENTES.d \
./src/MODELO.d \
./src/PEDIDOS.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


