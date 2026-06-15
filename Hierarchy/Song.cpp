#include "Track.h"
#include <sstream>

using namespace std;

Song::Song(
    string title,
    Date release,
    int duration,
    double size,
    string format,
    string artist,
    string album,
    string lyrics
) : Track(title, release, duration, size, format), artist(artist), album(album), lyrics(lyrics) {}

string Song::getLyrics() const {
    return lyrics;
}

Track* Song::clone() const {
    return new Song(*this);
}

string Song::toString() const {
    stringstream ss;

    ss << release.year << "-" << release.month << "-" << release.day << "|";
    ss << id << "|";
    ss << title << "|";
    ss << duration << "|";
    ss << size << "|";
    ss << format << "|";
    ss << artist << "|";
    ss << album << "|";
    ss << lyrics << "|";
    
    return ss.str();
}