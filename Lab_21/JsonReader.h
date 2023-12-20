#ifndef JSONREADER_H
#define JSONREADER_H
#include "fstream"
#include "vector"
#include "QColor"
#include "FilmClass.h"


class JsonReader : public AbstractClass{
public:
        JsonReader(const std::string& filename);

        bool isOpen() override ;
        std::vector<Film> readAll() override ;
        int getMaxId(const std::vector<Film>& film);

private:
        std::ifstream fin;
};

#endif // JSONREADER_H
