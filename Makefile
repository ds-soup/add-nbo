TARGET=add-nbo

ALL : add-nbo
	g++ -o add-nbo add-nbo.cpp
clean:
	rm -f $(TARGET)
	rm -f *.o
