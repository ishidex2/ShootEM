#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QMap>
#include <QElapsedTimer>
#include <QMouseEvent>
#include <QFile>
#include <QJsonObject>
#include <QPaintEvent>
#include "gamedata.h"
#include "faketext.h"
#include "player.h"
#include "map.h"
#include "dialog.h"
#include "liveshud.h"
#include "mapobject.h"
#include "background.h"
#include "camera.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();
private:
    LivesHud testLivesHud;
	Player you;
	QMap<int, bool> keys;
    QTimer frameUpdate;
	QElapsedTimer frameInterval;
	Ui::Widget *ui;
	Camera cam;
	LeafShieldWeapon testWeapon;
	Background testBg;
	Background bricksBg;
	Dialog testDialog;
    Map testmap;
	bool dashRReleased;
	bool dashLReleased;


	CoolDown dashIntervalR;
	CoolDown dashIntervalL;

	//Animation Managers
	AnimationManager<QRect> teamRed;
	AnimationManager<QRect> teamBlue;
	AnimationManager<QRect> goldMember;
private slots:
	void update();
protected:
	void mousePressEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *e);
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);
};

#endif // WIDGET_H
