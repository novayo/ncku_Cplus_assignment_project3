#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "human.h"
#include "human_enemy.h"
#include "human_player.h"
#include "score.h"
#include "mushroom.h"
#include "dialoggameover.h"
#include "dialogabout.h"
#include "addplayerhealth.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent * event);
    void gameStart();
    static bool getStatusGame();
    static void setStatusMushroom();
    static bool getStatusMushroom();
    static void setStatusaddplayerhealth();
    static bool getStatusaddplayerhealth();
    static bool getstatuspauseGame();


public slots:
    void check();
    void generateMushroom();
    void generateaddplayerhealth();

private slots:

    void on_button_Start_clicked();
    void on_button_About_clicked();
    void on_button_quit_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *player;
    Human* human_player_ptr;
    Human* human_enemy_ptr;
    Mushroom* mushroom;
    AddPlayerHealth* addplayerhealth;
    static bool statusGame;
    static bool statuspauseGame;
    static bool statusMushroom;
    static bool statusaddplayerhealth;
    static bool statusplayer;
    static bool statusenemy;

    Score* score;
    QTimer* tmrLabelScore;
    QTimer* tmrGenerateMushroom;
    QTimer* tmrGenerateaddplayerhealth;

    DialogGameOver* dialoggameover;
    DialogAbout* dialogabout;
};

#endif // MAINWINDOW_H
