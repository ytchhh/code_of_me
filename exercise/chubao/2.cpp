#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
 
const int MX = 308;
const double eps = 0.00001;
struct V{
    double _x, _y;
    V(){}
    V(double x, double y):_x(x),_y(y){}
    V operator *(double mul) const{
        return V(mul*_x, mul*_y);
    }
    V operator +(const V & v1) const{
        return V(_x+v1._x, _y+v1._y);
    }
    double dis(const V & v1){
        double sum1 = _x - v1._x; sum1 *= sum1;
        double sum2 = _y - v1._y; sum2 *= sum2;
        return sqrt(sum1+sum2);
    }
    void pf(){
        printf("point :%lf %lf\n", _x, _y);
    }
};
int n;
V point[MX];
V speed[MX];
V now[MX];
double get_dis(double tim){
    for(int i = 0; i < n; i++){
        now[i] = point[i] + speed[i]*tim;
    }
    double tmax = 0.0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            tmax = max(tmax, now[i].dis(now[j]));
        }
    }
    return tmax;
 
}
int main(){
    while(cin>>n){
        for(int i = 0;i < n;i++){
            double x,y;scanf("%lf%lf",&x,&y);
            point[i] = V(x,y);
            double sx,sy;scanf("%lf%lf",&sx,&sy);
            speed[i] = V(sx,sy);
        }
        double res = get_dis(0.00);
        double flag_time = 0.00;
        double l = 0.00;
        double r = 1000000000.00;
        while(l < r - eps){
            double mid1 = (l+r)*0.5;
            double mid2 = (l+mid1)*0.5;
            double res1 = get_dis(mid1);
            double res2 = get_dis(mid2);
            if(res1 < res2){
                l = mid2;
                if(res1 < res){
                    flag_time = mid1;
                    res = res1;
                }
            }
            else{
                r = mid1;
                if(res2 < res){
                    flag_time = mid1;
                    res = res1;
                }
            }
        }
        printf("%.2lf %.2lf\n",flag_time, res);
    }
    return 0;
}
