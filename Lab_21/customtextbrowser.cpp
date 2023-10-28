#include <CustomTextBrowser.h>


// Метод для добавления текста определенного цвета
void CustomTextBrowser::appendColoredText(const QString& text, const QColor& color)
{
    QTextCursor cursor = this->textCursor(); // Получаем текущий курсор
    QTextCharFormat originalFormat = cursor.charFormat(); // Сохраняем оригинальный формат

    QTextCharFormat format;
    format.setForeground(QBrush(color));
    cursor.setCharFormat(format); // Устанавливаем формат для цвета
    cursor.insertText(text + "\n"); // Добавляем текст с символом новой строки

    // Восстанавливаем оригинальный формат
    cursor.setCharFormat(originalFormat);
    this->setTextCursor(cursor); // Устанавливаем курсор обратно
}
