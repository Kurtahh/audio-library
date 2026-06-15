CXX = g++
CXXFLAGS = -std=c++17 -Wall

HIERARCHY_OBJS = Hierarchy/Track.o Hierarchy/Song.o Hierarchy/Podcast.o
CONTAINER_OBJS = Container/AudioLibrary.o Container/StatStrategy.o

module.o: $(HIERARCHY_OBJS) $(CONTAINER_OBJS)
	$(CXX) $(CXXFLAGS) -c $(HIERARCHY_OBJS) $(CONTAINER_OBJS) -o module.o

Hierarchy/Track.o: Hierarchy/Track.cpp Hierarchy/Track.h
	$(CXX) $(CXXFLAGS) -c Hierarchy/Track.cpp -o Hierarchy/Track.o

Hierarchy/Song.o: Hierarchy/Song.cpp Hierarchy/Track.h
	$(CXX) $(CXXFLAGS) -c Hierarchy/Song.cpp -o Hierarchy/Song.o

Hierarchy/Podcast.o: Hierarchy/Podcast.cpp Hierarchy/Track.h
	$(CXX) $(CXXFLAGS) -c Hierarchy/Podcast.cpp -o Hierarchy/Podcast.o

Container/AudioLibrary.o: Container/AudioLibrary.cpp Container/AudioLibrary.h
	$(CXX) $(CXXFLAGS) -c Container/AudioLibrary.cpp -o Container/AudioLibrary.o

Container/StatStrategy.o: Container/StatStrategy.cpp Container/StatStrategy.h
	$(CXX) $(CXXFLAGS) -c Container/StatStrategy.cpp -o Container/StatStrategy.o

demo: $(HIERARCHY_OBJS) $(CONTAINER_OBJS) demo.cpp
	$(CXX) $(CXXFLAGS) $(HIERARCHY_OBJS) $(CONTAINER_OBJS) demo.cpp -o demo

run_demo: demo
	./demo

test: $(HIERARCHY_OBJS) $(CONTAINER_OBJS) test.cpp
	$(CXX) $(CXXFLAGS) $(HIERARCHY_OBJS) $(CONTAINER_OBJS) test.cpp -o test

run_test: test
	./test

clean:
	rm -f $(HIERARCHY_OBJS) $(CONTAINER_OBJS) module.o demo test

rebuild: clean demo test