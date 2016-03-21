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
	virtual AbstractMatrix& operator+( AbstractMatrix&)=0;
	virtual AbstractMatrix& operator*( AbstractMatrix&)=0;
	virtual AbstractMatrix& operator*( int&)=0;
	virtual AbstractMatrix& operator-( AbstractMatrix&)=0;
	//  virtual AbstractMatrix& reverse()=0;
	virtual AbstractMatrix& transpose()=0;
	//  virtual float determinant()=0;
	virtual ostream& print(ostream& o)=0;
	//  virtual istream& read(istream& o)=0;
	virtual void set(int i, int j, float data)=0;
	virtual float get(int i, int j)=0;
	virtual int getN()=0;
	virtual int getM()=0;
	virtual float get_(int i)=0;

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
				data[i] = i;
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
		virtual AbstractMatrix& operator* (int& z)
		{
			matrix* mult = new matrix (n,m);
			for (int i(0); i < n*m; i++)
		 {
			 mult->data[i] = z * data[i];
		 }

			return *mult;
		}
		float get_(int i)
		{
			return data[i];
		}
		virtual AbstractMatrix& operator=( AbstractMatrix& t)
		{
			n = t.getN();
			m = t.getM();
			delete data;
			data = new float [n*m];
			for(int i = 0; i < n*m; i++)
		 {
			 data[i] = t.get_(i);
		 }

			AbstractMatrix& l = *this;
			return l;
		}
		AbstractMatrix& operator+ (AbstractMatrix& f)
		{
			matrix* t = new matrix (f.getN(),f.getM());
			if (n==f.getN() && m==f.getM())
			{
				for (int i(0); i <f.getN()*f.getM(); i++ )
				{
					t->data[i] = this->data[i] + f.get_(i);
				}
			}
			return *t;
		}
		AbstractMatrix& operator- (AbstractMatrix& f)
		{
			matrix* t = new matrix (f.getN(),f.getM());
			if (n==f.getN() && m==f.getM())
			{
				for (int i(0); i <f.getN()*f.getM(); i++ )
				{
					t->data[i] = this->data[i] - f.get_(i);
				}
			}
			return *t;
		}
		AbstractMatrix& operator* (AbstractMatrix& f)
		{
			matrix* mult = new matrix(n,f.getM());
			for (int i(0); i< n*m; i++)
				for (int j(0); j < f.getM()*f.getN(); j++)
				{
					if (i%m == j/(f.getM()))
					{
						 mult->data[(i/m)*f.getM() + j%f.getM()] += data[i]*f.get_(j);
					}
				}
				return *mult;

		}
		int getN()
		{ return n;}
		int getM()
		{ return m;}
		AbstractMatrix& transpose()
		{
			matrix* p = new matrix(n,m);
			for (int i(0); i < n*m; i++)
			{
				p->data[i/m + m*(i%m)] = data[i];
			}
			return *p;
		}
		ostream& print( ostream& o)
		{
			for (int i(0); i < n*m; i++)
			{	
				if(i%n == 0)
				{
					o<<endl;
				}
				o<<'\t'<<data[i];
			}
			o<<endl;
			return o;
		}
};
int main()
{
	matrix S(3,3);
	S.print(cout);
	matrix Q(3,3);
	matrix M (3,3);
	M = S*Q;
	M.print(cout);
}
