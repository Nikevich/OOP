#include "csvwriter.h"
#include "csvreader.h"


        CsvWriter::CsvWriter(const std::string& filename){
            fout.open(filename, std::ios::app);
        }
        bool CsvWriter::isOpen(){
            return fout.is_open();
        }
        CsvWriter::~CsvWriter() {
            if (fout.is_open()) {
                fout.close();
            }
        }

        void CsvWriter::writeAll(const std::vector<Film>& films) {

            CsvReader csvReader("Films.csv");
            for (const Film& film : films) {
                fout << film.id << ";" << film.name << ";" << film.genre << ";" << film.year << ";" << film.color.name().toStdString() << "\n";
            }
        }

        std::ofstream fout;


