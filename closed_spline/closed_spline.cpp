#include "closed_spline.h"
#include "../abstract_spline/abstract_spline.h"

/* Closed Spline Methods */
ClosedSpline::ClosedSpline(vector<pair<double, double> > points, double t_size)
{
        //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size);
}


void ClosedSpline::getH()
{
    int n = Px.size();

    h.push_back(0);

    for(int i = 1; i < n; i++)
        h.push_back(sqrt(pow(Px[i]-Px[i-1],2) + pow(Py[i]-Py[i-1],2)));

    h.push_back(0);
}


void ClosedSpline::getLambda()
{
    int n = h.size();

    lambda.push_back( (h[n-2]+h[0]) / (h[n-2] + h[0] + h[1]) );
    for(int i=1;i < n-2;i++)
        lambda.push_back( (h[i-1] + h[i]) / (h[i-1] + h[i] + h[i+1]) );
    
    lambda.push_back( (h[n-3] + h[n-2]) / ( h[n-3] + h[n-2] + h[0]) );
}


void ClosedSpline::getMi()
{
    int n = h.size();
    
    mi.push_back(h[0]/(h[0]+h[1]+h[2]));
    for(int i=1;i < n-2;i++)
        mi.push_back( h[i] / (h[i] + h[i+1] + h[i+2]) );
    
    mi.push_back(h[n-2]/(h[n-2]+h[n-1]+h[1]));
}


void ClosedSpline::InitializeVectors(double t_size)
{    
    ClosedSpline::setLambda();
    ClosedSpline::setMi();
    AbstractSpline::setDelta();
    AbstractSpline::setA_B_C();
    AbstractSpline::setM();
    AbstractSpline::setD();
    AbstractSpline::setR_L();

    AbstractSpline::PrintAll((AbstractSpline*)this);

    CalculateSplinePoints(t_size);

    cout << "\n\n";
    for(int i = 0; i < points_x.size(); i++)
        fprintf(stdout,"%.3f\t%.3f\n",points_x[i],points_y[i]);
    cout << "\n\n";
}