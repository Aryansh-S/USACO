################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../helloworld11.cpp 

OBJS += \
./helloworld11.o 

CPP_DEPS += \
./helloworld11.d 


# Each subdirectory must supply rules for building sources it contributes
helloworld11.o: ../helloworld11.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"helloworld11.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


