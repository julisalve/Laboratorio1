################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/2DO\ EXMANE\ CACHORRO.c \
../src/Controller.c \
../src/LinkedList.c \
../src/Parser.c \
../src/cachorros.c \
../src/general.c 

OBJS += \
./src/2DO\ EXMANE\ CACHORRO.o \
./src/Controller.o \
./src/LinkedList.o \
./src/Parser.o \
./src/cachorros.o \
./src/general.o 

C_DEPS += \
./src/2DO\ EXMANE\ CACHORRO.d \
./src/Controller.d \
./src/LinkedList.d \
./src/Parser.d \
./src/cachorros.d \
./src/general.d 


# Each subdirectory must supply rules for building sources it contributes
src/2DO\ EXMANE\ CACHORRO.o: ../src/2DO\ EXMANE\ CACHORRO.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/2DO EXMANE CACHORRO.d" -MT"src/2DO\ EXMANE\ CACHORRO.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


