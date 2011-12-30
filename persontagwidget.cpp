#include "persontagwidget.h"
#include <QGridLayout>
#include <QListWidgetItem>

#include <KIcon>
#include <KLocale>

#include <Nepomuk/Resource>
#include <Nepomuk/Query/Term>
#include <Nepomuk/Query/Query>
#include <Nepomuk/Query/QueryServiceClient>
#include <Nepomuk/Query/Result>
#include <Nepomuk/Query/ResourceTypeTerm>
#include <Nepomuk/Vocabulary/PIMO>

PersonTagWidget::PersonTagWidget(QWidget *parent) :
    KDialog(parent)
{
    setWindowTitle( i18n("Person Tagging-Gwenview") );
    setWindowIcon(KIcon("gwenview"));
    setupGui();
    setPersons();
}

void PersonTagWidget::setupGui()
{
    QGridLayout* layout = new QGridLayout(mainWidget());

    m_personWidget = new QListWidget(mainWidget());
    layout->addWidget(m_personWidget,0,0);

}

void PersonTagWidget::setPersons()
{
    Nepomuk::Query::Term term =  Nepomuk::Query::ResourceTypeTerm( Nepomuk::Vocabulary::PIMO::Person() );
    Nepomuk::Query::Query query(term);
    query.setLimit( 35 );
    QList<Nepomuk::Query::Result> results = Nepomuk::Query::QueryServiceClient::syncQuery( query );
    Q_FOREACH( const Nepomuk::Query::Result& result,results) {
        QListWidgetItem* person = new QListWidgetItem(result.resource().genericLabel(),m_personWidget);
        person->setCheckState(Qt::Unchecked);
        person->setIcon(KIcon("user-identity"));
    }

}
