#ifndef VALIDATE_H
#define VALIDATE_H
#include <QString>
#include <QRegularExpression>

class validate
{
public:
    validate();

    bool isValidWithSpace(QString &str);

    bool isValidString(QString &str) ;
    QString deleteMiddleSpace(QString &str);

};

#endif // VALIDATE_H
