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

private:
        std::ofstream fout;
};

#endif // CSVWRITER_H
