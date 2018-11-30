PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = FitTheShapes.o Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o
CXXFLAGS += -std=c++11

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	#$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all: FitTheShapes

FitTheShapes:	$(OBJS)
	$(CXX) -o $@ $^
Rectangle:	$(OBJS) 
	$(CXX) -o $@ $^
Triangle:	$(OBJS) 
	$(CXX) -o $@ $^
Circle:	$(OBJS) 
	$(CXX) -o $@ $^
ComposedShape:	$(OBJS) 
	$(CXX) -o $@ $^
Polygon:	$(OBJS) 
	$(CXX) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr FitTheShapes $(OBJS)
