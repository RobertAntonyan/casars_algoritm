#include <iostream>
#include <fstream>

class Cesar
{

public:
    Cesar();
    ~Cesar();

public:
    void setKey(int);
    int getKey() const;
    void encrypt();
    void decrypt();

private:
    int m_key;
    std::fstream fin;
    std::fstream fout;
};

//#endif //Cesar