#pragma once

#include <string>

struct Date {
    int year;
    int month;
    int day;
};

class Track {
    protected:
        int id;
        std::string title;
        Date release;
        int duration;
        double size;
        std::string format;

        Track(
            std::string title,
            Date release,
            int duration,
            double size,
            std::string format
        );

    public:
        virtual ~Track() = default;
        virtual Track* clone() const = 0;
        virtual std::string toString() const = 0;
        bool operator<(const Track& other) const;

        int getID() const;
        std::string getTitle() const;
        Date getDate() const;
        int getDuration() const;
        double getSize() const;
        std::string getFormat() const;

        void setID(int newID);
};

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

        std::string getLyrics() const;
};

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