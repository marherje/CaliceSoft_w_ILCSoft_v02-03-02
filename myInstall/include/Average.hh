#ifndef __Average_hh__
#define __Average_hh__ 1

#include <cmath>

/**  Collect input values and calculate mean/RMS upon request
 *
 *   This class keeps sum, sum-of-squares and number of input
 *   values to calculate mean/RMS. Templated value data type
 *   allows for flexible memory managemant, while internal
 *   calculations are done in double precision to avoid numerical
 *   cut-offs.
 *
 *   @author Niels.Meyer@desy.de
 *   @date   January 2008
 */

template<class T>
class Average{
public:
  Average():_num(0), _sum(0), _sum2(0){}
  ~Average(){}


  //  add value to be considered for next call to mean/RMS calculation
  Average& addValue(T e){
    _sum += e;
    _sum2 += e*e;
    if ( _num == 0 ) {
      _min = e;
      _max = e;
    } else {
      _min = _min < e ? _min : e;
      _max = _max > e ? _max : e;
    }
    ++_num;
    return (*this);
  }


  //  reset members
  Average& reset(){
    _sum = 0;
    _sum2 = 0;
    _num = 0;
    return (*this);
  }


  //  return functions for private members
  const unsigned int getNumberOfValues() const { return _num; }

  const T getSum() const { return _sum; }

  const T getSumOfSquares() const { return _sum2; }


  //  value and uncertainty of mean
  const T getMean() const {
    return _num>0
      ? _sum / (T)_num
      : 0;
  }

  const T getMeanUncertainty() const {
    return _num>0
      ? (T)getRMS() / sqrt( (T)_num )
      : 0;
  }

  //  value and uncertainty of RMS
  const T getRMS() const {
    return getMeanOfSquares() <= getMeanSquared() ? 0 :
      (T)sqrt( getMeanOfSquares() - getMeanSquared() );
  }
  const T getRMSUncertainty() const {
    return 2*getMeanUncertainty();
  }

  //  smallest and largest input value
  const T getMin() const {
    return _min;
  }

  const T getMax() const {
    return _max;
  }

protected:
  //  internal calculations done in double precision independent of T
  const double getSumSquared() const {
    return (double)_sum*(double)_sum;
  }

  const double getMeanSquared() const {
    return _num>0 ? getSumSquared()/(double)(_num*_num) : 0;
  }

  const double getMeanOfSquares() const {
    return _num>0 ? _sum2/(double)_num : 0;
  }

private:
  //  data members
  unsigned int _num;
  T _sum;
  T _sum2;
  T _min;
  T _max;

}; // class ConfigurationAverage

#endif
