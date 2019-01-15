#pragma once
#include "../abstract_spline/abstract_spline.h"


class ClosedSpline : public AbstractSpline
{
    public:
        ClosedSpline(vector<pair<double, double> > points, double t_size);
    protected:
        void getMi();
        void getLambda();
        void getH();
        void InitializeVectors(double t_size);
};