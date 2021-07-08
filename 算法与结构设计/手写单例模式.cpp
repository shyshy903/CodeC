class Singleton
{
private:
    /* data */
    static Singleton* p;
public:
    Singleton(/* args */);
    Singleton* getInstance();
};

Singleton* Singleton::p = new Singleton;

Singleton* Singleton::getInstance(){
    return p;
}
