#include <iostream>
using namespace std;
class AbstractMatrix
{
protected:
	int n;
    int m;
    float* data;
public:
    
  //AbstractMatrix();
  ////AbstractMatrix(int m, int n);
  //  virtual AbstractMatrix& operator+( AbstractMatrix&)=0;
  //  virtual AbstractMatrix& operator*( AbstractMatrix&)=0;
  //  virtual AbstractMatrix& operator*( int&)=0;
  //  virtual AbstractMatrix& operator-( AbstractMatrix&)=0;
  //  virtual AbstractMatrix& reverse()=0;
  //  virtual AbstractMatrix& transpose()=0;
  //  virtual float determinant()=0;
  //  virtual ostream& print(ostream& o)=0;
  //  virtual istream& read(istream& o)=0;
    virtual void set(int i, int j, float data)=0;
    virtual float get(int i, int j)=0;
    virtual int getN()=0;
    virtual int getM()=0;
 //   virtual bool failed()=0;
};
class matrix : public AbstractMatrix
{
public: matrix()
		{
			data = NULL;
			n = 0;
			m = 0;
		}
		matrix (int _n, int _m)
		{
			n = _n;
			m = _m;
			data = new float [n*m];
			for (int i(0); i < n*m; i++)
			{
				data[i] = 1.0*i;
			}
		}
	 float get (int i, int j)
		{
			return data[i*n + j];
		}
	 void set (int i, int j, float _data)
	 {
		 data[i*n + j] = _data;
	 }
	 /*virtual matrix& operator* (float& z)
	 {
		 matrix* mult = new matrix (n,m);
		 for (int i(0); i < n*m; i++)
		 {
			 mult->data[i] = z * data[i];
		 }
		
		 return *mult;
	 }*/
	int getN()
	{ return n;}
	int getM()
	{ return m;}
};
int main()
{
	matrix S(2,23);
	float z = 10;
	cout<<S.getM();
	
}
