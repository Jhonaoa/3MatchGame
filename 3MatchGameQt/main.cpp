
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "rect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Rect **rect;


    //crear la escena

    QGraphicsScene * scene = new QGraphicsScene();

    //crea un objeto para poner dentro de la escena

    rect = new Rect * [8];
    for (int i = 0 ; i<8 ; i ++)
        rect[i] = new Rect[8];


// añadir el objeto a la escena


    int posx = 0,posy = 0;

            for (int i = 0; i<8; i++)
            {
                for (int j= 0; j<8; j++)
                {

                    rect[i][j].setRect(posx,posy,50,50);
                    scene->addItem(&rect[i][j]);

                    posx += 50;
                }
                posx =0;
                posy +=50;
            }


//añadir un objeto tipo pintar o mostrar

    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    view->setFixedSize(800,800);
    view->setSceneRect(0,0,400,400);








    return a.exec();
}
/*#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * miEscena = new QGraphicsScene;
    miEscena->setSceneRect(0,0,800,600);


    int coordenadaX = 0;
    int coordenadaY = 0;
    for (int i = 1; i <= 8; i ++)
    {

        for(int j = 1; j <= 8; j ++)
        {
            if (coordenadaX == 100 and coordenadaY == 50)
            {
                QGraphicsRectItem * misRectangulos = new QGraphicsRectItem;
                misRectangulos->setRect(coordenadaX,coordenadaY,50,50);
                miEscena->addItem(misRectangulos);
                misRectangulos->setBrush(Qt::red);

             }
            else
            {
                QGraphicsRectItem * misRectangulos = new QGraphicsRectItem;
                misRectangulos->setRect(coordenadaX,coordenadaY,50,50);
                miEscena->addItem(misRectangulos);
            }

           coordenadaX += 50;
        }

        coordenadaX = 0;
        coordenadaY += 50;

    }







//        QGraphicsRectItem * miRectangulo = new QGraphicsRectItem;
//    miRectangulo->setRect();


    //    miEscena->addItem(miRectangulo);

    //    miRectangulo->setBrush(Qt::red);

    QGraphicsView *suMadre = new QGraphicsView;
    suMadre->setScene(miEscena);

    suMadre->show();

    return a.exec();
}*/
