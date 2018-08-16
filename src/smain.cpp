#include <QSqlDriverPlugin>
#include <QStringList>
#include "qsql_sqlite_p.h"

namespace ghg
{

class QSQLiteCipherDriverPlugin : public QSqlDriverPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QSqlDriverFactoryInterface" FILE "qsqlcipher.json")

public:
  QSQLiteCipherDriverPlugin();

  QSqlDriver* create(const QString&) Q_DECL_OVERRIDE;
};

QSQLiteCipherDriverPlugin::QSQLiteCipherDriverPlugin() : QSqlDriverPlugin()
{
}

QSqlDriver* QSQLiteCipherDriverPlugin::create(const QString& name)
{
  if(name == QLatin1String("QSQLCIPHER"))
  {
    QSQLiteDriver* driver = new QSQLiteDriver();
    return driver;
  }
  return 0;
}

}

#include "smain.moc"
