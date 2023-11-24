#include <vector>
#include <cmath>
#include <iostream>

class LineFitter {
  private:
    std::vector<float> _x;
    std::vector<float> _y;
    std::vector<float> _sigma_y;
    float _S, _S_x, _S_xx, _S_xy, _S_y, _Delta;
  public:
    LineFitter() {};
    LineFitter(std::vector<float> x, std::vector<float> y, std::vector<float> sigma_y);
    void addPoint(float x, float y, float sigma_y);
    void clear();
    void fit();
    bool converged();
    float getM();
    float getMError();
    float getB();
    float getBError();
    float getMBCovariance();

    float eval(float x);
    float evalError(float x);

    int GetNDF(); 
    float GetChisquare();
};
