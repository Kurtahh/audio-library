CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = Track.o Song.o Podcast.o AudioLibrary.o StatStrategy.o

module.o: $(OBJS)
	$(CXX) $(CXXFLAGS) -c $(OBJS) -o module.o

Track.o: Track.cpp Track.h
	$(CXX) $(CXXFLAGS) -c Track.cpp -o Track.o

Song.o: Song.cpp Track.h
	$(CXX) $(CXXFLAGS) -c Song.cpp -o Song.o

Podcast.o: Podcast.cpp Track.h
	$(CXX) $(CXXFLAGS) -c Podcast.cpp -o Podcast.o

AudioLibrary.o: AudioLibrary.cpp AudioLibrary.h
	$(CXX) $(CXXFLAGS) -c AudioLibrary.cpp -o AudioLibrary.o

StatStrategy.o: StatStrategy.cpp StatStrategy.h
	$(CXX) $(CXXFLAGS) -c StatStrategy.cpp -o StatStrategy.o

demo: $(OBJS) demo.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) demo.cpp -o demo

run_demo: demo
	./demo

test: $(OBJS) test.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) test.cpp -o test

run_test: test
	./test

clean:
	rm -f $(OBJS) module.o demo test

rebuild: clean demo test