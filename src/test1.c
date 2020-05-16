#include <math.h>
#include <stdio.h>
#include "distance_calculator.h"
#define d2r (M_PI / 180.0)
#define radius 6367.77

double haversine_dist(double lat1, double long1, double lat2, double long2);
int main(int argc, char **argv)
{
	double dist, la1=44.248422, lo1=8.528469, la2=44.41305, lo2=8.88286;
	dist=haversine_dist(la1,lo1,la2,lo2);
	printf("dist = %f \n",dist);
	return 0;
}

double haversine_dist(double lat1, double long1, double lat2, double long2)
{
    double dlong = (long2 - long1) * d2r;
    double dlat = (lat2 - lat1) * d2r;
    double a = pow(sin(dlat/2.0), 2) + cos(lat1*d2r) * cos(lat2*d2r) * pow(sin(dlong/2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = radius * c;
    return d*1000;
}
