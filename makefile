#Jacob Cox
#Type "make all" to compile all files

all: Cox_Jacob_File_Gen Cox_Jacob_Times

Cox_Jacob_File_Gen: Cox_Jacob_File_Gen.cpp
	g++ -std=c++11 -Wall Cox_Jacob_File_Gen.cpp -o Cox_Jacob_File_Gen

Cox_Jacob_Times: Cox_Jacob_Times.cpp
	g++ -std=c++11 -Wall Cox_Jacob_Times.cpp -o Cox_Jacob_Times


