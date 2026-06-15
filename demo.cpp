#include "Hierarchy/Track.h"
#include "Container/AudioLibrary.h"
#include "Container/StatStrategy.h"
#include "Exceptions.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    AudioLibrary library;

    library.add(new Song("Bohemian Rhapsody", {1975, 10, 31}, 354, 8.5, "MP3", "Queen", "A Night at the Opera", "Is this the real life?"));
    library.add(new Song("Imagine", {1971, 10, 11}, 187, 4.2, "FLAC", "John Lennon", "Imagine", "Imagine there's no heaven..."));
    library.add(new Podcast("The Joe Rogan Experience", {2024, 1, 15}, 7200, 164.0, "MP3", "Joe Rogan", "A long form conversation podcast."));
    library.add(new Podcast("Lex Fridman Podcast", {2024, 3, 10}, 10800, 243.0, "MP3", "Lex Fridman", "Conversations about science and technology."));

    // polymorphism
    for (AudioLibrary::Iterator it = library.begin(); it != library.end(); ++it) {
        cout << (*it)->toString() << endl;
    }

    Track* t = library.get(0);
    Song* s = dynamic_cast<Song*>(t);
    if (s != nullptr) {
        cout << "Lyrics: " << s->getLyrics() << endl;
    }

    // strategy
    library.setStrategy(new TotalDuration());
    cout << "Total duration: " << library.compute() << " seconds" << endl;

    library.setStrategy(new AverageDuration());
    cout << "Average duration: " << library.compute() << " seconds" << endl;

    library.setStrategy(new TotalSize());
    cout << "Total size: " << library.compute() << " MB" << endl;

    // deep copy
    AudioLibrary copy = library;
    cout << "Library copy:" << endl;
    cout << copy.toString() << endl;

    // callback
    vector<Track*> longTracks = library.filter([](Track* t) {
        return t->getDuration() > 300;
    });
    cout << "Long tracks (>300s):" << endl;
    for (Track* t : longTracks) {
        cout << t->toString() << endl;
    }

    vector<Track*> podcasts = library.filter([](Track* t) {
        return dynamic_cast<Podcast*>(t) != nullptr;
    });
    cout << "Podcasts only:" << endl;
    for (Track* t : podcasts) {
        cout << t->toString() << endl;
    }

    // iterator
    vector<Track*> tracks;
    for (AudioLibrary::Iterator it = library.begin(); it != library.end(); ++it) {
        tracks.push_back(*it);
    }
    sort(tracks.begin(), tracks.end(), [](Track* a, Track* b) {
        return *a < *b;
    });
    cout << "Tracks sorted by duration:" << endl;
    for (Track* t : tracks) {
        cout << t->toString() << endl;
    }

    return 0;
}