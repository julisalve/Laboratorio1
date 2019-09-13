################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clase\ 8\ bis.c 

OBJS += \
./src/clase\ 8\ bis.o 

C_DEPS += \
./src/clase\ 8\ bis.d 


# Each subdirectory must supply rules for building sources it contributes
src/clase\ 8\ bis.o: ../src/clase\ 8\ bis.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/clase 8 bis.d" -MT"src/clase\ 8\ bis.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


