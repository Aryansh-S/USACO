################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jan2016usaco1.cpp 

OBJS += \
./jan2016usaco1.o 

CPP_DEPS += \
./jan2016usaco1.d 


# Each subdirectory must supply rules for building sources it contributes
jan2016usaco1.o: ../jan2016usaco1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"jan2016usaco1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


