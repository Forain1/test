#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>


class Fighter : public QGraphicsObject
{
    Q_OBJECT

public:
    Fighter(QGraphicsItem *parent = nullptr)
        : QGraphicsObject(parent), currentFrame(0)
    {
        // 加载 6 张帧图像
        for (int i = 0; i < 7; ++i) {
            QString path = QString(":/src/image%1.png").arg(i);
            QPixmap pix(path);
            if (!pix.isNull()) {
                frames.append(pix);
            } else {
                qWarning() << "加载失败:" << path;
            }
        }

        // 启动帧动画
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Fighter::nextFrame);
        timer->start(100); // 每 100ms 播放一帧
    }

    QRectF boundingRect() const override {
        if (frames.isEmpty())
            return QRectF(0, 0, 64, 64);
        return QRectF(0, 0, frames[currentFrame].width(), frames[currentFrame].height());
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        if (!frames.isEmpty())
            painter->drawPixmap(0, 0, frames[currentFrame]);
    }

private slots:
    void nextFrame() {
        if (frames.isEmpty()) return;
        currentFrame = (currentFrame + 1) % frames.size();
        update();
    }

private:
    QVector<QPixmap> frames;
    int currentFrame;
    QTimer *timer;
};

// Qt 元对象宏（因为继承了 QObject）
#include "main.moc"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);

    Fighter *fighter = new Fighter();
    fighter->setPos(200, 200);
    scene.addItem(fighter);

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setFixedSize(820, 620);
    view.show();

    return app.exec();
}
