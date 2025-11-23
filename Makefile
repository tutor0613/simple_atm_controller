ATM_DEMO : atm_controller.o demo.o
	g++ -o ATM_DEMO atm_controller.o demo.o

atm_controller.o : src/atm_controller.hpp src/atm_controller.cpp
	g++ -c -o atm_controller.o src/atm_controller.cpp

demo.o : src/demo.cpp
	g++ -c -o demo.o src/demo.cpp



