proj6: wmobei2Proj6.o Island.o
	g++ -g -o proj6 wmobei2Proj6.o Island.o

wmobei2Proj5.o: wmobei2Proj6.cpp proj6.h
	g++ -g -c wmobei2Proj6.cpp

proj5Stack.o: Island.cpp proj6.h
	g++ -g -c Island.cpp

clean:
	rm wmobei2Proj6.o Island.o proj6