#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlDatabase>   // Основной класс для работы с БД
#include <QtSql/QSqlQuery>      // Класс для выполнения SQL-запросов
#include <QtSql/QSqlError>      // Для обработки ошибок SQL
#include <QtSql/QSqlRecord>     // Для работы с записями (результаты запроса)
#include <QTableView>
namespace dbmanagement {
class DbManager {
private:
    QSqlDatabase db;
    void openConnection(QString dbName);
public:
    DbManager();
    ~DbManager();
    void manageDatabase(QString dbName);
    void renderResultInConsole(QSqlQuery* sqlQuery);
    void renderResultInTable(QSqlQuery* sqlQuery, QTableView* table);
    void closeConnection();
    QSqlQuery* executeQuery(QString query);
};
}
#endif // DBMANAGER_H
