#ifndef CSVWRITER_H
#define CSVWRITER_H
#include "iostream"
#include "vector"
#include "fstream"
#include "CsvReader.h"


class CsvWriter{
        public:
        CsvWriter(const std::string& filename);
        bool isOpen();
        ~CsvWriter();
        void writeAll(const std::vector<Film>& films);

        friend std::ofstream& operator<<(std::ofstream& ofs, const Film& film) {
                ofs << film.id << ";" << film.name << ";" << film.genre << ";" << film.year << ";" << film.color.name().toStdString();
                return ofs;
            }

private:
        std::ofstream fout;
};

#endif // CSVWRITER_H
