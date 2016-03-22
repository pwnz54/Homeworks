#include <iostream>
using namespace std;
ostream& operator<<(ostream& o, string& s)
{
    o << s.c_str();
    return o;
}
istream& operator>>(istream& i, string& s)
{
    char buf[256];
    i >> buf;
    string tmp(buf);
    s = tmp;
    return i;
}
template<typename T>
class AbstractList
{
protected:
    T _default;
public :
    virtual void sort(bool (*f) (T* first, T* second)) = 0;
    virtual T get(int index) = 0;
    virtual void set(int index, T data) = 0;
    virtual void insert(int index, T data) = 0;
    virtual T remove(int index) = 0;
    virtual int len() = 0;
    void push(T data)
    {
        insert(0, data);
    }
    virtual T pop()
    {
        if (empty())
            return _default;
        else
            return remove(0);
    }
    virtual bool empty()
    {
        return len() == 0;
    }
    virtual ostream& print(ostream& o)
    {
        for (int i = 0; i < len(); i ++)
        {
            o << get(i) << endl;
        }
        return o;
    }
    virtual istream& read(istream& in)
    {
        int count;
        in >> count;
        for (int i = 0 ; i < count ; i ++)
        {
            T tmp;
            in >> tmp;
            insert(len(), tmp);
        }
        return in;
    }

};
template<typename T>
class list : public AbstractList<T>
{
    list* next;
    T data;

public:
     virtual int len()
    {
        int k = 0;
        list* tmp = this;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            k++;

        }
        return k-1;
    }

    virtual T get(int index)
    {
        list* tmp = this;
        if(index >= len())
        {
            return tmp->_default;
        }
        for (int i=0; i < len(); i++)
        {
            tmp = tmp->next;
            if (index == i)
            {
                return tmp->data;
            }
         }
        return tmp->_default;
      }
     virtual void set(int index, T data)
    {
         list* tmp = this;

         if (index >= len())
         {
             return;
         }
         for (int i(0); i < len(); i++)
         {
             tmp = tmp->next;
             if (index == i)
             {
                 tmp->data = data;
                 return ;
             }

         }
         return;
    }
    list(T data, T _default)
    {
        this->data = data;
        this->_default = _default;
        this->next = NULL;
     }
    list(T _default)// constr for head
    {
        this->next =NULL;
        this->_default = _default;

    }
    list()
    {
        this->next = NULL;
    }
     virtual void insert(int index, T data)
    {
        list* tmp = this;
        list* nephew = new list(data, this->_default);
        if (index >= len())
        {
            int i = 0;
            while (i < len())
            {
                i++;
                tmp = tmp->next;
             }
            list* generals = tmp->next;
            tmp->next = nephew;
            nephew->next = generals;
            return;
        }
        for (int i(0); i<len(); i++)
        {

            if (i == index)
            {
                list* generals = tmp->next;
                tmp->next = nephew;
                nephew->next = generals;
            }
            tmp = tmp->next;
        }
        return;
    }
    virtual void sort(bool (*f) (T* first, T* second))
        {
           list* tmp = this;
           list* tmp1 = this;
           list* _next = this;
           list* prev = this;
           for (int i=0; i<len(); i++)
               for (int k=0;k<len()-1; k++)
               {
                 if (f(&(tmp->data), &(tmp->next->data)))
                   {
                    tmp1=tmp->next;
                    _next = tmp1->next;
                    prev->next = tmp1;
                    tmp1->next = tmp;
                    tmp->next = _next;
                    }
                    prev = tmp;
                    tmp = tmp->next;
               }
        }
     virtual T remove(int index)
    {
        list* power = this;
        for(int i(0); i < len(); i++)
        {

            if (i == index)
            {
                list* putin = power->next;
                power->next = putin->next;
                T inf = putin->data;
                delete putin;
                return inf;
            }
            power = power->next;
        }
        return this->_default;
    }
   virtual ~list()
    {
        next = NULL;
    }

    friend AbstractList<string>* get_init();
};

template <typename T>
bool compare (T* first, T* second)
{
    if (&first > &second)
        return true;
    else return false;
}

AbstractList<string>* get_init()
{
    list<string>* putin = new list<string>("Empty!!!");
    list<string>* putin2 = new list<string>();
    putin->next = putin2;
    return putin;
}


