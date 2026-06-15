#include "Track.h"
#include <sstream>

using namespace std;

Podcast::Podcast(
    string title,
    Date release,
    int duration,
    double size,
    string format,
    string host,
    string description
) : Track(title, release, duration, size, format), host(host), description(description) {}

Track* Podcast::clone() const {
    return new Podcast(*this);
}

string Podcast::toString() const {
    stringstream ss;

    ss << release.year << "-" << release.month << "-" << release.day << "|";
    ss << id << "|";
    ss << title << "|";
    ss << duration << "|";
    ss << size << "|";
    ss << format << "|";
    ss << host << "|";
    ss << description << "|";

    return ss.str();
}