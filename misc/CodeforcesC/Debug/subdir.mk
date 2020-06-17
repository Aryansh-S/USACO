################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mainfile.cpp 

OBJS += \
./mainfile.o 

CPP_DEPS += \
./mainfile.d 


# Each subdirectory must supply rules for building sources it contributes
mainfile.o: ../mainfile.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"mainfile.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


