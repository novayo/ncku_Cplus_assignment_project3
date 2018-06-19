#include "dialoggameover.h"
#include "ui_dialoggameover.h"

DialogGameOver::DialogGameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGameOver)
{
    ui->setupUi(this);

    QString messageGameOver;

    if (Human::getStatusPlayer() == true && Human::getStatusEnemy() == false){
        messageGameOver = "You Win !!! Game Over !\nYour Score: " + QString::number(Score::getScore()) + '\n' ;
    }
    else if (Human::getStatusPlayer() == false && Human::getStatusEnemy() == true){
        messageGameOver = "You Lose !!! Game Over !\nYour Score: " + QString::number(Score::getScore()) + '\n' ;
    }


    int textFont = 20;
    /// // set GameOver message // ///
    QFont font = ui->Label_GameOver->font();
    font.setPointSize(textFont);
    font.setBold(true);
    ui->Label_GameOver->setFont(font);

    ui->Label_GameOver->setText(messageGameOver);
    ui->Label_GameOver->setVisible(true);
    QPalette sample_palette;
    if (Human::getStatusPlayer() == true && Human::getStatusEnemy() == false){
        sample_palette.setColor(QPalette::WindowText, QColor(0,221,0));
    }
    else{
        sample_palette.setColor(QPalette::WindowText, QColor(255,0,0));
    }
    ui->Label_GameOver->setAutoFillBackground(true);
    ui->Label_GameOver->setPalette(sample_palette);
}

DialogGameOver::~DialogGameOver()
{
    delete ui;
}
