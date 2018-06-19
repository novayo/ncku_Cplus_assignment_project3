#include "dialogabout.h"
#include "ui_dialogabout.h"
#include <QCloseEvent>

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);

    int textFont = 15;
    /// // set GameOver message // ///
    QFont font = ui->Label_About->font();
    font.setPointSize(textFont);
    font.setBold(true);
    ui->Label_About->setFont(font);

    ui->Label_About->setVisible(true);
    QPalette sample_palette;

    sample_palette.setColor(QPalette::WindowText, QColor(247, 131, 180));

    ui->Label_About->setAutoFillBackground(true);
    ui->Label_About->setPalette(sample_palette);
}

DialogAbout::~DialogAbout()
{
    delete ui;
}
