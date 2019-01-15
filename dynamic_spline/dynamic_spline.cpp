#include "dynamic_spline.h"


DynamicSpline::DynamicSpline(vector<pair<double,double> > points, double t_size)
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



DynamicSpline::DynamicSpline(vector<pair<double,double> > points, double t_size, vector<double> v)
{
        //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size, v);

}

void DynamicSpline::getH()
{
    int n = Px.size();

    h.push_back(0);

    for(int i = 1; i < n; i++)
        h.push_back(sqrt(pow(Px[i]-Px[i-1],2) + pow(Py[i]-Py[i-1],2)));

    h.push_back(0);
}