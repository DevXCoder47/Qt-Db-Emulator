#include "dbmanager.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>   // Основной класс для работы с БД
#include <QtSql/QSqlQuery>      // Класс для выполнения SQL-запросов
#include <QtSql/QSqlError>      // Для обработки ошибок SQL
#include <QtSql/QSqlRecord>     // Для работы с записями (результаты запроса)
#include <QtSql/QSqlQueryModel>
#include <QTableView>
namespace dbmanagement {

DbManager::DbManager()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

void DbManager::manageDatabase(QString dbName) {
    openConnection(dbName);
}

void DbManager::renderResultInConsole(QSqlQuery* sqlQuery)
{

    QSqlRecord record = sqlQuery->record();
    int columnCount = record.count();

    QTextStream out(stdout);

    QString header;
    for(int i = 0; i < columnCount; i++)
        header += record.fieldName(i) += "\t";
    out << header << "\n";

    while(sqlQuery->next()) {
        QString row;
        for(int i = 0; i < columnCount; i++)
            row += sqlQuery->value(i).toString() += "\t";
        out << row << "\n";
    }
}

void DbManager::renderResultInTable(QSqlQuery* sqlQuery, QTableView *table)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(*sqlQuery));
    table->setModel(model);
    table->resizeColumnsToContents();
}

void DbManager::closeConnection()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "connection closed";
        QMessageBox::information(nullptr, "connection state", "connection closed");
    }
}

QSqlQuery* DbManager::executeQuery(QString query)
{
    QSqlQuery* sqlQuery = new QSqlQuery;
    sqlQuery->exec(query);
    return sqlQuery;
}

void DbManager::openConnection(QString dbName) {
    db.setDatabaseName("Driver={ODBC Driver 17 for SQL Server};Server=KOMPUTER\\SQLEXPRESS;Database=" + dbName + ";Trusted_Connection=yes;");
    if (db.open()) {
        qDebug() << "connection opened";
        QMessageBox::information(nullptr, "connection state", "connection opened");
    }
    else
        qDebug() << "Error" << db.lastError().text();
}

DbManager::~DbManager()
{
    closeConnection();
}

}
