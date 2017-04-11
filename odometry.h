//
// Created by User on 011 11.04.17.
//

#ifndef TEST_ODOMETRY_H
#define TEST_ODOMETRY_H

#endif //TEST_ODOMETRY_H
class odometry
{
private:
    double X_r;
    double Y_r;
    double A;
    double X_l;
    double Y_l;
    int Phase;

public:
    void set(double x_r,double y_r,double a,double x_l,double y_l);
    void push(double *out,int phase);
    odometry();
    ~odometry();
};
odometry::odometry()
{
    X_r=0;
    X_l=0;
    Y_r=0;
    Y_l=0;
    A=0;
}
odometry::~odometry(){}
void odometry::set(double x_r, double y_r, double a, double x_l, double y_l)
{
    X_r+=x_r;
    Y_r+=y_r;
    A+=a;
    X_l+=x_l;
    Y_l+=y_l;
}
void odometry::push(double *out,int phase)
{
    if (phase ==0||phase ==2) {
        out[0] = (X_r + X_l) / 2;
        out[1] = (Y_r + Y_l) / 2;
        out[2] = A;

    }else
    {
        if(phase==1)
        {
            out[0] = X_r;
            out[1] = Y_r;
            out[2] = A;
        }
        else
        {
            out[0] = X_l;
            out[1] = Y_l;
            out[2] = A;
        }
    }

}