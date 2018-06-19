#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <cstdlib>
#include <QImage>
#include <QBrush>
#include <cstdlib>
#include <ctime>
#include <QFont>

bool MainWindow::statusGame = false;
bool MainWindow::statusplayer = false;
bool MainWindow::statusMushroom = false;
bool MainWindow::statusenemy = false;
bool MainWindow::statuspauseGame = false;
bool MainWindow::statusaddplayerhealth = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));
    srandom(time(NULL));
    ///// set scene /////
    scene = new QGraphicsScene(0, 0, 600, 800);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/picture/img/background.png")));

    /// // set scroll bar invisible // ///
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    /// // set LabelScore invisible /// //
    ui->Label_Score->setVisible(false);
    ui->graphicsView->setVisible(false);

    /// // set LabelGameStart // ///
    QFont font = ui->LableGameStart->font();
    font.setPointSize(30);
    font.setBold(true);
    ui->LableGameStart->setFont(font);

    ui->LableGameStart->setText("Welcome to my raiden game!\n\nHint:\n\tWASD -> moving\n\tSpace -> shoot\n\tN -> Ulti(-30000000)\n\tExc -> pause");
    ui->LableGameStart->setVisible(true);
    QPalette sample_palette;

    sample_palette.setColor(QPalette::WindowText, QColor(0,221,0));

    ui->LableGameStart->setAutoFillBackground(true);
    ui->LableGameStart->setPalette(sample_palette);

    /// // set label score // ///
    font = ui->Label_Score->font();
    font.setPointSize(30);
    font.setBold(true);
    ui->Label_Score->setFont(font);

    ui->Label_Score->setVisible(false);

    sample_palette.setColor(QPalette::WindowText, QColor(73, 131, 180));

    ui->Label_Score->setAutoFillBackground(true);
    ui->Label_Score->setPalette(sample_palette);

    /// // set label health // ///
    font = ui->Label_Health->font();
    font.setPointSize(30);
    font.setBold(true);
    ui->Label_Health->setFont(font);

    ui->Label_Health->setVisible(false);

    sample_palette.setColor(QPalette::WindowText, QColor(73, 131, 180));

    ui->Label_Health->setAutoFillBackground(true);
    ui->Label_Health->setPalette(sample_palette);

    /// //set progress bar // ///
    ui->progressBarEnemyHealth->setMaximum(100);
    ui->progressBarEnemyHealth->setVisible(false);

    /// // set label health number // ///
    ui->Label_Health_number->setVisible(false);
    ui->Label_Health_number_2->setVisible(false);
    ui->Label_Health_number_3->setVisible(false);
    ui->Label_Health_number_4->setVisible(false);
    ui->Label_Health_number_5->setVisible(false);

    /// // set label skill // ///
    font = ui->Label_Health->font();
    font.setPointSize(30);
    font.setBold(true);
    ui->Label_Skill->setFont(font);

    ui->Label_Skill->setVisible(false);

    sample_palette.setColor(QPalette::WindowText, QColor(73, 131, 180));

    ui->Label_Skill->setAutoFillBackground(true);
    ui->Label_Skill->setPalette(sample_palette);

    /// // set label skill number // ///
    ui->Label_skill_number->setVisible(false);
    ui->Label_skill_number_2->setVisible(false);
    ui->Label_skill_number_3->setVisible(false);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (Human::getStatusPlayer() == true && Human::getStatusEnemy() == true && statusGame == true && statuspauseGame == false){
        int setVisible = 3;
        int speed = 50;
        switch(event->key()) {
        case Qt::Key_Up:
        case Qt::Key_W:
            if (human_player_ptr->y() - speed > human_enemy_ptr->pixmap().height()){
                human_player_ptr->setPos(human_player_ptr->x(), human_player_ptr->y()-speed);
            }
            else{
                human_player_ptr->setPos(human_player_ptr->x(), human_enemy_ptr->pixmap().height() );
            }
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            if (human_player_ptr->y() + human_player_ptr->pixmap().height() + speed < scene->height()){
                human_player_ptr->setPos(human_player_ptr->x(), human_player_ptr->y()+speed);
            }
            else{
                human_player_ptr->setPos(human_player_ptr->x(), scene->height() - human_player_ptr->pixmap().width() - setVisible);
            }
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            if (human_player_ptr->x() - speed > 0){
                human_player_ptr->setPos(human_player_ptr->x()-speed, human_player_ptr->y());
            }
            else{
                human_player_ptr->setPos(0, human_player_ptr->y());
            }
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            if (human_player_ptr->x() + human_player_ptr->pixmap().width() + speed < scene->width()){
                human_player_ptr->setPos(human_player_ptr->x()+speed, human_player_ptr->y());
            }
            else{
                human_player_ptr->setPos(scene->width() - human_player_ptr->pixmap().width() - setVisible, human_player_ptr->y());
            }
            break;
        case Qt::Key_Space:
            human_player_ptr->shoot();
            break;
        case Qt::Key_N:
            human_player_ptr->specialSkill();
            break;
        case Qt::Key_Escape:
            ui->button_Start->setText(QString("Continue"));
            scene->removeItem(human_player_ptr);
            scene->removeItem(human_enemy_ptr);
            if (statusMushroom == true){
                scene->removeItem(mushroom);
            }
            if (statusaddplayerhealth == true){
                scene->removeItem(addplayerhealth);
            }
            ui->Label_Score->setVisible(false);
            ui->Label_Score_number->setVisible(false);
            ui->Label_Health->setVisible(false);
            ui->Label_Skill->setVisible(false);
            ui->graphicsView->setVisible(false);
            ui->graphicsView->setVisible(false);
            ui->Label_Health_number->setVisible(false);
            ui->Label_Health_number_2->setVisible(false);
            ui->Label_Health_number_3->setVisible(false);
            ui->Label_Health_number_4->setVisible(false);
            ui->Label_Health_number_5->setVisible(false);
            ui->Label_skill_number->setVisible(false);
            ui->Label_skill_number_2->setVisible(false);
            ui->Label_skill_number_3->setVisible(false);
            ui->progressBarEnemyHealth->setVisible(false);
            ui->LableGameStart->setVisible(true);
            ui->button_About->setVisible(true);
            ui->button_About->setEnabled(true);
            ui->button_Start->setVisible(true);
            ui->button_Start->setEnabled(true);
            ui->button_quit->setVisible(true);
            ui->button_quit->setEnabled(true);
            statuspauseGame = true;
            break;
        }
    }
    else if (Human::getStatusPlayer() == true && Human::getStatusEnemy() == true && statusGame == true && statuspauseGame == true){
        if (event->key() == Qt::Key_Space){
            on_button_Start_clicked();
        }
    } else{
        // player destroyed
    }
}

void MainWindow::gameStart()
{
    if (ui->button_Start->text() == QString("Start")){
        ///// set score /////
        score = new Score();

        ///// set player /////
        human_player_ptr = new Human_Player();
        human_player_ptr->setPos(scene->width()/2, scene->height()/2);

        ///// set enemy /////
        human_enemy_ptr = new Human_Enemy();
        human_enemy_ptr->setPos(scene->width()/2 - human_enemy_ptr->pixmap().width()/2, 0);

        /// // set check timer // ///
        tmrLabelScore = new QTimer();
        connect(tmrLabelScore, SIGNAL(timeout()), this, SLOT(check()));

        /// // generate mushroom // ///
        tmrGenerateMushroom = new QTimer();
        connect(tmrGenerateMushroom, SIGNAL(timeout()), this, SLOT(generateMushroom()));

        /// // generate addplayerhealth // ///
        tmrGenerateaddplayerhealth = new QTimer();
        connect(tmrGenerateaddplayerhealth, SIGNAL(timeout()), this, SLOT(generateaddplayerhealth()));

        tmrLabelScore->start(100);
        tmrGenerateMushroom->start(10000);
        tmrGenerateaddplayerhealth->start(30000);
        statusGame = true;
    }

    ui->Label_Score->setVisible(true);
    ui->Label_Score_number->setVisible(true);
    ui->Label_Health->setVisible(true);
    ui->Label_Skill->setVisible(true);
    ui->graphicsView->setVisible(true);
    ui->Label_Health_number->setVisible(true);
    ui->Label_Health_number_2->setVisible(true);
    ui->Label_Health_number_3->setVisible(true);
    ui->Label_Health_number_4->setVisible(true);
    ui->Label_Health_number_5->setVisible(true);
    ui->Label_skill_number->setVisible(true);
    ui->Label_skill_number_2->setVisible(true);
    ui->Label_skill_number_3->setVisible(true);
    ui->graphicsView->setScene(scene);
    scene->addItem(human_player_ptr);
    scene->addItem(human_enemy_ptr);
    if (statusMushroom == true){
        scene->addItem(mushroom);
    }
    ui->progressBarEnemyHealth->setValue(Human::getHealthEnemy());
    ui->progressBarEnemyHealth->setVisible(true);
    statuspauseGame = false;
}

bool MainWindow::getStatusGame()
{
    return statusGame;
}

void MainWindow::setStatusMushroom()
{
    statusMushroom = !statusMushroom;
}

bool MainWindow::getStatusMushroom()
{
    return statusMushroom;
}

void MainWindow::setStatusaddplayerhealth()
{
    statusaddplayerhealth = !statusaddplayerhealth;
}

bool MainWindow::getStatusaddplayerhealth()
{
    return statusaddplayerhealth;
}

bool MainWindow::getstatuspauseGame()
{
    return statuspauseGame;
}

void MainWindow::check()
{
    if (getstatuspauseGame() == false){
        if (statusGame == true){
            /// // print score // ///
            QFont font = ui->Label_Score_number->font();
            font.setPointSize(25);
            font.setBold(true);
            ui->Label_Score_number->setFont(font);

            ui->Label_Score_number->setText(QString::number(Score::getScore()));
            ui->Label_Score_number->setVisible(true);
            QPalette sample_palette;
            if (Score::getScore() >= 0){
                sample_palette.setColor(QPalette::WindowText, QColor(0,221,0));
            }
            else{
                sample_palette.setColor(QPalette::WindowText, QColor(255,0,0));
            }
            ui->Label_Score_number->setAutoFillBackground(true);
            ui->Label_Score_number->setPalette(sample_palette);

            /// // if Human::getHealthEnemy() change, then set value to progress bar // ///
            if (ui->progressBarEnemyHealth->value() != Human::getHealthEnemy()){
                ui->progressBarEnemyHealth->setValue(Human::getHealthEnemy());
            }

            if (Human::getHealthPlayer() == 5){
                ui->Label_Health_number->setVisible(true);
                ui->Label_Health_number_2->setVisible(true);
                ui->Label_Health_number_3->setVisible(true);
                ui->Label_Health_number_4->setVisible(true);
                ui->Label_Health_number_5->setVisible(true);
            }
            else if (Human::getHealthPlayer() == 4){
                ui->Label_Health_number->setVisible(true);
                ui->Label_Health_number_2->setVisible(true);
                ui->Label_Health_number_3->setVisible(true);
                ui->Label_Health_number_4->setVisible(true);
                ui->Label_Health_number_5->setVisible(false);
            }
            else if (Human::getHealthPlayer() == 3){
                ui->Label_Health_number->setVisible(true);
                ui->Label_Health_number_2->setVisible(true);
                ui->Label_Health_number_3->setVisible(true);
                ui->Label_Health_number_4->setVisible(false);
                ui->Label_Health_number_5->setVisible(false);
            }
            else if (Human::getHealthPlayer() == 2){
                ui->Label_Health_number->setVisible(true);
                ui->Label_Health_number_2->setVisible(true);
                ui->Label_Health_number_3->setVisible(false);
                ui->Label_Health_number_4->setVisible(false);
                ui->Label_Health_number_5->setVisible(false);
            }
            else if (Human::getHealthPlayer() == 1){
                ui->Label_Health_number->setVisible(true);
                ui->Label_Health_number_2->setVisible(false);
                ui->Label_Health_number_3->setVisible(false);
                ui->Label_Health_number_4->setVisible(false);
                ui->Label_Health_number_5->setVisible(false);
            }
            else if (Human::getHealthPlayer() == 0){
                ui->Label_Health_number->setVisible(false);
                ui->Label_Health_number_2->setVisible(false);
                ui->Label_Health_number_3->setVisible(false);
                ui->Label_Health_number_4->setVisible(false);
                ui->Label_Health_number_5->setVisible(false);
            }

            if (Human::getNumTrump() == 3){
                ui->Label_skill_number->setVisible(true);
                ui->Label_skill_number_2->setVisible(true);
                ui->Label_skill_number_3->setVisible(true);
            }
            else if (Human::getNumTrump() == 2){
                ui->Label_skill_number->setVisible(true);
                ui->Label_skill_number_2->setVisible(true);
                ui->Label_skill_number_3->setVisible(false);
            }
            else if (Human::getNumTrump() == 1){
                ui->Label_skill_number->setVisible(true);
                ui->Label_skill_number_2->setVisible(false);
                ui->Label_skill_number_3->setVisible(false);
            }
            else if (Human::getNumTrump() == 0){
                ui->Label_skill_number->setVisible(false);
                ui->Label_skill_number_2->setVisible(false);
                ui->Label_skill_number_3->setVisible(false);
            }

            /// // if player or enemy dead, then show dialogGameOver // ///
            if (Human::getStatusPlayer() == false || Human::getStatusEnemy() == false){
                statusGame = false;
                dialoggameover = new DialogGameOver();
                delete tmrLabelScore;

                dialoggameover->exec();
                this->close();
            }
        }
    }
}

void MainWindow::generateMushroom()
{
    if (getstatuspauseGame() == false){
        if (statusGame == true){
            mushroom = new Mushroom();
            int tmp = scene->width() - mushroom->pixmap().width();
            int randx = rand()%tmp;
            mushroom->setPos(randx, human_enemy_ptr->pixmap().height());
            scene->addItem(mushroom);
            statusMushroom = true;
        }
    }
}

void MainWindow::generateaddplayerhealth()
{
    if (getstatuspauseGame() == false){
        if (statusGame == true){
            addplayerhealth = new AddPlayerHealth();
            int tmp = scene->width() - addplayerhealth->pixmap().width();
            int randx = rand()%tmp;
            addplayerhealth->setPos(randx, human_enemy_ptr->pixmap().height());
            scene->addItem(addplayerhealth);
            statusaddplayerhealth = true;
        }
    }
}

void MainWindow::on_button_Start_clicked()
{
    ui->LableGameStart->setVisible(false);
    ui->button_About->setVisible(false);
    ui->button_About->setEnabled(false);
    ui->button_Start->setVisible(false);
    ui->button_Start->setEnabled(false);
    ui->button_quit->setVisible(false);
    ui->button_quit->setEnabled(false);

    gameStart();
}

void MainWindow::on_button_About_clicked()
{
    dialogabout = new DialogAbout();

    dialogabout->exec();
}

void MainWindow::on_button_quit_clicked()
{
    this->close();
}
