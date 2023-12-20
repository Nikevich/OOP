#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"
#include <vector>
#include <algorithm>
#include <iostream>
#include <QtCore>
#include <QString>
#include <QTextBrowser>
#include <QFileDialog>
#include "CsvReader.h"
#include "JsonReader.h"
#include "CsvWriter.h"
#include "mainwindow.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // Кнопка Search
{
    filterVectorFilm.clear();
    CsvReader csv("Films.csv");
    if (csv.isOpen()){
        mainVectorFilm = csv.readAll();
    }

    QString search1 = ui->lineEdit->text();
    QString search2 = ui->lineEdit_5->text();
    QString search3 = ui->lineEdit_6->text();
    ui->textBrowser->clear();

    Film searchFilm;
        searchFilm.name = search3.toStdString();
        searchFilm.genre = search2.toStdString();
        searchFilm.year = search1.toInt();

    for (const Film& film : mainVectorFilm) {
//        bool match = true;





//        if (!search3.isEmpty() && QString::fromStdString(film.name) != search3) {
//            match = false;
//        }

//        if (!search2.isEmpty() && QString::fromStdString(film.genre) != search2) {
//            match = false;
//        }

//        if (!search1.isEmpty()) {
//            int year = QString::number(film.year).toInt();
//            int searchYear = search1.toInt();
//            if (year > searchYear) {
//                match = false;
//            }
//        }


        if (film == searchFilm) {
//            filterVectorFilm.push_back(film);
            ui->textBrowser->appendColoredText(QString::number(film.id) + ":     " + QString::fromStdString(film.name) + ";     " + QString::fromStdString(film.genre) + ";     " + QString::number(film.year), film.color);
        }
    }
}

template <typename T>
T calculateAverage(const std::vector<T>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Vector is empty, cannot calculate average.");
    }

    T sum = 0;
    for (const auto& number : numbers) {
        sum += number;
    }

    return sum / static_cast<T>(numbers.size());
}

void MainWindow::on_pushButton_7_clicked() // Кнопка Lab 8
{

    std::vector<int> intVector = {1, 2, 3, 4, 5};
        try {
            int averageInt = calculateAverage(intVector);
            std::cout << "Average (int): " << averageInt << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

//        std::vector<double> doubleVector = {1.5, 2.5, 3.5, 4.5, 5.5};
//        try {
//            double averageDouble = calculateAverage(doubleVector);
//            std::cout << "Average (double): " << averageDouble << std::endl;
//        } catch (const std::invalid_argument& e) {
//            std::cerr << "Error: " << e.what() << std::endl;
//        }

}

void MainWindow::on_pushButton_2_clicked() // Кнопка Add File
{
    QString filter = "CSV Files (*.csv);;JSON Files (*.json);;All Poor Files (*)";
    QString filterName = "Select your fakin file";
    QString selectedFilePath = QFileDialog::getOpenFileName(this, filterName, "", filter);

    filterVectorFilm.clear();
    mainVectorFilm.clear();

    if(selectedFilePath.endsWith(".csv", Qt::CaseInsensitive)){
        try {
                CsvReader csv(selectedFilePath.toStdString());
                if (csv.isOpen()) {
                    mainVectorFilm = csv.readAll();

                    int lineNumber = 0;
                    for (const auto& film : mainVectorFilm) {
                        ++lineNumber;
//                        if (!std::isdigit(film.year)) {
//                            throw std::invalid_argument("Invalid year format at line " + std::to_string(lineNumber));
//                        }

                        if (film.genre != "Action" && film.genre != "Drama" && film.genre != "Comedy") {
                            throw std::invalid_argument("Invalid genre at line " + std::to_string(lineNumber));
                        }

                    }
                }
            } catch (const std::exception& e) {
            std::cerr << "Error processing CSV data: " << e.what() << std::endl;
            }
    }

    if(selectedFilePath.endsWith(".json", Qt::CaseInsensitive)){
        JsonReader json(selectedFilePath.toStdString());
        if (json.isOpen()){
            mainVectorFilm = json.readAll();
        }
    }

    ui->textBrowser->clear();



        for (auto const& film : mainVectorFilm) {
               ui->textBrowser->appendColoredText(QString::number(film.id) + ":     " + QString::fromStdString(film.name) + ";     " + QString::fromStdString(film.genre) + ";     " + QString::number(film.year), film.color);
        }
}

void MainWindow::on_pushButton_6_clicked() // Кнопка Add Json
{
    filterVectorFilm.clear();
    mainVectorFilm.clear();
    JsonReader json("Films.json");
    if (json.isOpen()){
        mainVectorFilm = json.readAll();
    }

    ui->textBrowser->clear();



        for (auto const& film : mainVectorFilm) {
               ui->textBrowser->appendColoredText(QString::number(film.id) + ":     " + QString::fromStdString(film.name) + ";     " + QString::fromStdString(film.genre) + ";     " + QString::number(film.year), film.color);
        }
}




void MainWindow::on_pushButton_3_clicked() // Кнопка Save File

{

    QString textToSave = ui->textBrowser->toPlainText();

    if (!textToSave.isEmpty()) {

        QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", QString(), "Текстовые файлы (*.csv)");

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                stream << textToSave;
                file.close();
            }
        }
    }
}







void MainWindow::on_pushButton_5_clicked() // Кнопка Sort
{

    std::vector<Film> tempVectorFilm;
    if(!filterVectorFilm.empty()){
        tempVectorFilm = filterVectorFilm;
    } else {
        tempVectorFilm = mainVectorFilm;
    }
    std::sort(tempVectorFilm.begin(), tempVectorFilm.end(), [](const Film& lhs, const Film& rhs){
        return lhs.name < rhs.name;
    });


    ui->textBrowser->clear();


    for (const Film& film : tempVectorFilm) {
         ui->textBrowser->appendColoredText(QString::number(film.id) + ":     " + QString::fromStdString(film.name) + ";     " + QString::fromStdString(film.genre) + ";     " + QString::number(film.year), film.color);
    }
}

void MainWindow::on_pushButton_4_clicked() // Кнопка Add
{
    CsvReader csvReader("Films.csv");
    std::vector<Film> existingFilms = csvReader.readAll(); // Считываем существующие записи
    CsvWriter csvWriter("Films.csv");
    if (csvWriter.isOpen()) {
        Film newFilm; // Создаем новую игру

        QString add1 = ui->lineEdit_4->text();
        QString add2 = ui->lineEdit_3->text();
        QString add3 = ui->lineEdit_7->text();

        // Присваиваем значения из lineEdit переменным объекта newFilm
        newFilm.name = add1.toStdString();
        newFilm.genre = add2.toStdString();
        newFilm.year = add3.toInt();
        int maxId = csvReader.getMaxId(existingFilms);

        // Увеличиваем максимальное значение ID на 1 для новой записи
        newFilm.id = maxId + 1;

        // Выбран цвет из ComboBox
        QString selectedColor = ui->comboBox->currentText();
        QColor filmColor;

        // Преобразуем текст в цвет
        if (selectedColor == "Красный") {
            filmColor = QColor(Qt::red);
        } else if (selectedColor == "Зеленый") {
            filmColor = QColor(Qt::green);
        } else if (selectedColor == "Синий") {
            filmColor = QColor(Qt::blue);
        } else if (selectedColor == "Желтый") {
            filmColor = QColor(Qt::yellow);
        }

        newFilm.color = filmColor; // Присваиваем цвет игры
        std::vector<Film> newFilms = {newFilm}; // Создаем вектор с новой игрой

        // Добавляем новые данные в файл
        csvWriter.writeAll(newFilms);
    }
}







void MainWindow::on_comboBox_activated(const QString &arg1)
{

}
