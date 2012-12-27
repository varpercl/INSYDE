#include "vector2d.h"

Vector2D::Vector2D(){
    x = y = 0;
}

Vector2D::Vector2D(double x, double y){
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(double x0, double y0, double x1, double y1){
    x = x1-x0;
    y = y1-y0;
}

Vector2D::Vector2D(QPointF ptIni, QPointF ptFin){
    QPointF pt = ptFin-ptIni;
    x = pt.x();
    y = pt.y();
}

Vector2D::Vector2D(QPointF pt)
{
    x = pt.x();
    y = pt.y();
}

Vector2D::Vector2D(float modulo, float angle){
    x = modulo*cos(angle);
    y = modulo*sin(angle);
}

void Vector2D::setX(double x){
    this->x = x;
}

//double Vector2D::getX(){
//    return x;
//}

void Vector2D::setY(double y){
    this->y = y;
}

//double Vector2D::getY(){
//    return y;
//}

double Vector2D::getModulo(){
    return hypot(x, y);
}

void Vector2D::setModulo(double mod){
    double ang = getAngle();
    x = mod*cos(ang);
    y = mod*sin(ang);
}

double Vector2D::getAngle(){
    if(x < 0){
        return M_PI + atan(y/x);
    }else if(x > 0){
        if(y < 0){
            return 2*M_PI + atan(y/x);
        }else{
            return atan(y/x);
        }
    }else{
        if(y < 0){
            return 3*M_PI/2;
        }else if(y > 0){
            return M_PI/2;
        }else{
            return 0;
        }
    }
}

void Vector2D::setAngle(double angle){
    double mod = hypot(x, y);
    x = mod*cos(angle);
    y = mod*sin(angle);
}

double Vector2D::getAngleDeg()
{
//    return
    return 0;
}

void Vector2D::setAngleDeg(double angle)
{
    double mod = hypot(x, y);
    double angRad = angle*M_PI/180;
    x = mod*cos(angRad);
    y = mod*sin(angRad);
}

bool Vector2D::isParallel(Vector2D vector){
    return (x / vector.x) == (y / vector.y);
}

bool Vector2D::isPerpendicular(Vector2D vector){
    return *this * vector == 0;
}

Vector2D Vector2D::getPerpendicular(Direction angle)
{
    double Vx = 0, Vy = 0;
    switch(angle){
        case ClockWise:
            if(y == 0){
                return Vector2D(0, x);
            }
            Vx = hypot(x, y)/sqrt(1+((x*x)/(y*y)));
            Vy = -Vx*x/y;
            if(y > 0){
                Vx = -Vx;
                Vy = -Vy;
            }
            break;
        case CounterClockWise:
            if(y == 0){
                return Vector2D(0, -x);
            }
            Vx = hypot(x, y)/sqrt(1+((x*x)/(y*y)));
            Vy = -Vx*x/y;
            if(y < 0){
                Vx = -Vx;
                Vy = -Vy;
            }
    }
    return Vector2D(Vx, Vy);
}

QPointF Vector2D::toPointF()
{
    return QPointF(x, y);
}

bool Vector2D::operator==(const Vector2D &vector){
    return (this->x == vector.x && this->y == vector.y);
}

bool Vector2D::operator!=(const Vector2D &vector){
    return (this->x != vector.x || this->y != vector.y);
}

Vector2D &Vector2D::operator=(const Vector2D &vector){
    this->x = vector.x;
    this->y = vector.y;

    return *this;
}

double Vector2D::operator*(const Vector2D &vector){
    return (this->x * vector.x) + (this->y * vector.y);
}

Vector2D &Vector2D::operator *(const double k)
{
    x *= k;
    y *= k;
    return *this;
}

Vector2D &Vector2D::operator+(const Vector2D &vector){
    this->x = this->x + vector.x;
    this->y = this->y + vector.y;

    return *this;
}

Vector2D &Vector2D::operator-(const Vector2D &vector){
    this->x = this->x - vector.x;
    this->y = this->y - vector.y;

    return *this;
}

//VectorR2 VectorR2::operator=(const VectorR2 &vector){
////    this->x = vector.x;
////    this->y = vector.y;
////    return *this;
//}
