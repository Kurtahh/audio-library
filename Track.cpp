#include "Track.h"

using namespace std;

Track::Track(
    string title,
    Date release,
    int duration,
    double size,
    string format
) : id(0), title(title), release(release), duration(duration), size(size), format(format) {}

bool Track::operator<(const Track& other) const {
    return duration < other.duration;
}

int Track::getID() const {
    return id;
}

void Track::setID(int newID) {
    id = newID;
}

string Track::getTitle() const {
    return title;
}

Date Track::getDate() const {
    return release;
}

int Track::getDuration() const {
    return duration;
}

double Track::getSize() const {
    return size;
}

string Track::getFormat() const {
    return format;
}