#pragma once
#include <string>

// Represents a calendar date
struct Date {
    int year;
    int month;
    int day;
};

// Abstract base class for all audio tracks.
// Provides common fields (title, release date, duration, size, format)
// and a polymorphic interface for cloning and string representation.
class Track {
    protected:
        int id;
        std::string title;
        Date release;
        int duration; // in seconds
        double size;  // in MB
        std::string format; // e.g. "MP3", "FLAC"

        // Protected constructor — only callable by derived classes
        Track(
            std::string title,
            Date release,
            int duration,
            double size,
            std::string format
        );
        Track(const Track&) = default;
    public:
        virtual ~Track() = default;

        // Returns a polymorphic deep copy of this track (Prototype pattern)
        virtual Track* clone() const = 0;

        // Returns a delimited string representation of this track.
        // Audiobook::toString() throws NotImplementedException instead.
        virtual std::string toString() const = 0;

        // Compares tracks by duration for sorting
        bool operator<(const Track& other) const;

        int getID() const;
        void setID(int newID);
        std::string getTitle() const;
        Date getDate() const;
        int getDuration() const;
        double getSize() const;
        std::string getFormat() const;
};

// Represents a music track with an artist, album, and lyrics
class Song : public Track {
    std::string artist;
    std::string album;
    std::string lyrics;
    public:
        Song(
            std::string title,
            Date release,
            int duration,
            double size,
            std::string format,
            std::string artist,
            std::string album,
            std::string lyrics
        );

        Track* clone() const override;
        std::string toString() const override;

        // Returns the lyrics of the song — only available on Song (use dynamic_cast to access)
        std::string getLyrics() const;
};

// Represents a podcast episode with a host and description
class Podcast : public Track {
    std::string host;
    std::string description;
    public:
        Podcast(
            std::string title,
            Date release,
            int duration,
            double size,
            std::string format,
            std::string host,
            std::string description
        );

        Track* clone() const override;
        std::string toString() const override;
};

// Represents an audiobook with an author, synopsis, and page count.
// toString() throws NotImplementedException — to be implemented by a colleague.
class Audiobook : public Track {
    std::string author;
    std::string synopsis;
    int pageCount;
    public:
        Audiobook(
            std::string title,
            Date release,
            int duration,
            double size,
            std::string format,
            std::string author,
            std::string synopsis,
            int pageCount
        );

        Track* clone() const override;
        std::string toString() const override;
};