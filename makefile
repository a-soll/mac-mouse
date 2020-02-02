CXX = g++
CXXFLAGS = -g
FRMWRKS = -framework Carbon
OBJS = main.cpp

mouse: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(FRMWRKS) -o mouse

clean:
	rm -f *.o mouse
