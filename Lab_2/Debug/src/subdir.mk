################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lab_2.cpp \
../src/consumerapp.cpp \
../src/imiapp.cpp \
../src/procapp.cpp 

OBJS += \
./src/Lab_2.o \
./src/consumerapp.o \
./src/imiapp.o \
./src/procapp.o 

CPP_DEPS += \
./src/Lab_2.d \
./src/consumerapp.d \
./src/imiapp.d \
./src/procapp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -pedantic -pedantic-errors -Wall -Wextra -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


