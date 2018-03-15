#include "MaFenetre.h"
#include <QSet>

MaFenetre::MaFenetre(QWidget *parent) : QMainWindow(parent)
{
    read_csv (m_mat, m_vet, "data.csv");

    setFixedSize(800,600);

    m_com1= new QComboBox(this);
    m_com1->move(200,50);
    initComboBox(0,m_com1);

    m_com2= new QComboBox(this);
    m_com2->move(m_com1->x()+140,m_com1->y());
    initComboBox(1,m_com2);

    m_com3= new QComboBox(this);
    m_com3->move(m_com2->x()+140,m_com1->y());
    initComboBox(2,m_com3);

    m_bou = new QPushButton("Prédire", this);
    m_bou->move(m_com1->x()-50,m_com1->y()+50);
    m_bou->adjustSize();

    m_tra = new QLabel(this);
    m_tra->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_tra->move(320, 300);

    m_tab = new QTableWidget(this);
    m_tab->move(10,m_bou->y()+100);
    m_tab->setRowCount(m_mat.size());
    m_tab->setColumnCount(m_vet.size());

    for(unsigned i(0);i<m_mat.size();++i)
        for(unsigned j(0);j<m_vet.size();++j)
            m_tab->setItem(i,j,new QTableWidgetItem(m_mat[i][j].c_str()));

    for(unsigned i(0);i<m_vet.size();++i)
        m_tab->setHorizontalHeaderItem(i,new QTableWidgetItem(m_vet[i].c_str()));


    m_tab->setMinimumSize(750,400);


    // Associer signaux et les slots
    connect(m_bou,SIGNAL(clicked(bool)),this,SLOT(setPredire()));
    connect(m_com1, SIGNAL(currentIndexChanged(const QString &)),this, SLOT(setCouleur()));
}

void MaFenetre::setPredire(){

}

void MaFenetre::setCouleur(){
    couleur = m_com1->currentText();
    m_tra->setText(">>"+couleur+"<<");
}


void MaFenetre::initComboBox(int column,QComboBox* m_box){

    m_lab = new QLabel (m_vet[column].c_str(),this);
    m_lab->setFont(QFont("Verdana",12));
    QStringList list;
    list.append("None Provided");
    for(unsigned i(0); i < m_mat.size();++i){
        list.append(m_mat[i][column].c_str());
    }
    list.removeDuplicates();
    m_box->addItems(list);
    m_box->adjustSize();
    m_lab->move(m_box->x()+5,m_box->y()-20);
    m_lab->adjustSize();
}
