#include "Hierarchy/Track.h"
#include "Container/AudioLibrary.h"
#include "Container/StatStrategy.h"
#include "Exceptions.h"
#include <iostream>
#include <cassert>

using namespace std;

void testCRUD() {
    AudioLibrary library;

    library.add(new Song("Bohemian Rhapsody", {1975, 10, 31}, 354, 8.5, "MP3", "Queen", "A Night at the Opera", "Is this the real life?"));
    library.add(new Podcast("The Joe Rogan Experience", {2024, 1, 15}, 7200, 164.0, "MP3", "Joe Rogan", "A long form conversation podcast."));

    assert(library.size() == 2);
    assert(library.get(0)->getTitle() == "Bohemian Rhapsody");
    assert(library.get(1)->getTitle() == "The Joe Rogan Experience");

    library.update(0, new Song("Imagine", {1971, 10, 11}, 187, 4.2, "FLAC", "John Lennon", "Imagine", "Imagine there's no heaven..."));
    assert(library.get(0)->getTitle() == "Imagine");

    library.remove(1);
    assert(library.size() == 1);

    cout << "CRUD tests passed." << endl;
}

void testDeepCopy() {
    AudioLibrary library;
    library.add(new Song("Bohemian Rhapsody", {1975, 10, 31}, 354, 8.5, "MP3", "Queen", "A Night at the Opera", "Is this the real life?"));

    AudioLibrary copy = library;
    assert(copy.size() == library.size());
    assert(copy.get(0) != library.get(0));
    assert(copy.get(0)->getTitle() == library.get(0)->getTitle());

    cout << "Deep copy tests passed." << endl;
}

void testStrategy() {
    AudioLibrary library;
    library.add(new Song("Bohemian Rhapsody", {1975, 10, 31}, 354, 8.5, "MP3", "Queen", "A Night at the Opera", "Is this the real life?"));
    library.add(new Song("Imagine", {1971, 10, 11}, 187, 4.2, "FLAC", "John Lennon", "Imagine", "Imagine there's no heaven..."));

    try {
        library.compute();
        assert(false);
    } catch (const StrategyNotSetException& e) {
        cout << "StrategyNotSetException caught correctly." << endl;
    }

    library.setStrategy(new TotalDuration());
    assert(library.compute() == 541);

    library.setStrategy(new AverageDuration());
    assert(library.compute() == 270.5);

    library.setStrategy(new TotalSize());
    assert(library.compute() == 12.7);

    cout << "Strategy tests passed." << endl;
}

void testFilter() {
    AudioLibrary library;
    library.add(new Song("Bohemian Rhapsody", {1975, 10, 31}, 354, 8.5, "MP3", "Queen", "A Night at the Opera", "Is this the real life?"));
    library.add(new Song("Imagine", {1971, 10, 11}, 187, 4.2, "FLAC", "John Lennon", "Imagine", "Imagine there's no heaven..."));
    library.add(new Podcast("The Joe Rogan Experience", {2024, 1, 15}, 7200, 164.0, "MP3", "Joe Rogan", "A long form conversation podcast."));

    auto longTracks = library.filter([](Track* t) { return t->getDuration() > 300; });
    assert(longTracks.size() == 2);

    auto podcasts = library.filter([](Track* t) { return dynamic_cast<Podcast*>(t) != nullptr; });
    assert(podcasts.size() == 1);

    cout << "Filter tests passed." << endl;
}

void testAudiobook() {
    // Audiobook is not yet implemented. The following shows how it should be used
    // once implemented. The constructor should initialize all inherited Track fields
    // plus author, synopsis, and pageCount.
    //
    // Audiobook book("The Great Gatsby", {1925, 4, 10}, 18000, 400.0, "MP3",
    //                "F. Scott Fitzgerald", "A story of the American dream.", 180);
    //
    // clone() should return a deep copy of the audiobook:
    // Track* copy = book.clone();
    // assert(copy->getTitle() == "The Great Gatsby");
    // delete copy;
    //
    // toString() must throw NotImplementedException:
    // try {
    //     book.toString();
    //     assert(false);
    // } catch (const NotImplementedException& e) {
    //     cout << "NotImplementedException caught correctly." << endl;
    // }

    cout << "Audiobook tests documented (awaiting implementation)." << endl;
}

int main() {
    testCRUD();
    testDeepCopy();
    testStrategy();
    testFilter();
    testAudiobook();

    cout << "All tests passed." << endl;
    return 0;
}