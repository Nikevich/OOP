#ifndef CSVREADER_H
#define CSVREADER_H
#include "fstream"
#include "vector"
#include "QColor"
#include "FilmClass.h"

class CsvReader : public AbstractClass{
public:
        CsvReader(const std::string& filename);

        bool isOpen() override ;
        std::vector<Film> readAll() override ;
        int getMaxId(const std::vector<Film>& film);

private:
        std::ifstream fin;
};

#endif // CSVREADER_H
