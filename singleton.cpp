#include <iostream>

class Singleton
{
  private:
    static Singleton*instance;
    Singleton(){}

  public:
    static Singleton* getInstance()
    {
      if (instance == 0)
      {
        instance = new Singleton;
      }
      
      return instance;
    }
};

Singleton* Singleton::instance = 0;

int main()
{
  Singleton *s = Singleton::getInstance();
  Singleton *r = Singleton::getInstance();
  
  //print out addresses of instances, will be the same. 
  cout << s << endl;
  cout << r << endl;
  
  return 0;
}
