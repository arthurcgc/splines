#pragma once
#include "../abstract_spline/abstract_spline.h"


class DynamicSpline : public AbstractSpline
{
    public:
        DynamicSpline(vector<pair<double, double> > points, double t_size);
        DynamicSpline(vector<pair<double,double> > points, double t_size, vector<double> v);
    protected:
        void getH();
};