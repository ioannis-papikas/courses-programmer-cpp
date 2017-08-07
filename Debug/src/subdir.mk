################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Chromosome.cpp \
../src/CourseManager.cpp \
../src/CoursesProgrammer.cpp \
../src/Gene.cpp \
../src/Program.cpp 

OBJS += \
./src/Chromosome.o \
./src/CourseManager.o \
./src/CoursesProgrammer.o \
./src/Gene.o \
./src/Program.o 

CPP_DEPS += \
./src/Chromosome.d \
./src/CourseManager.d \
./src/CoursesProgrammer.d \
./src/Gene.d \
./src/Program.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


