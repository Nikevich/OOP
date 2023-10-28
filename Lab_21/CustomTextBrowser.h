#ifndef CUSTOMTEXTBROWSER_H
#define CUSTOMTEXTBROWSER_H
// 4 лаба
#include <QTextBrowser>
#include <QTextCharFormat>
#include <QTextCursor>

class CustomTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    void appendColoredText(const QString& text, const QColor& color);
    CustomTextBrowser(QWidget* parent = nullptr) : QTextBrowser(parent) {}
};



#endif // CUSTOMTEXTBROWSER_H
