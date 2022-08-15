#include "cesar.h"
#include <string>

Cesar::Cesar()
{
    std::string path1 = "encrypt.txt";
    std::string path2 = "decrypt.txt";
    fin.open(path1, std::fstream::in | std::fstream::out | std::fstream::app);
    fout.open(path2, std::fstream::in | std::fstream::out | std::fstream::app);
    if (fin.is_open() && fout.is_open())
    {
        std::cout << "File is open." << std::endl;
    }
    else
    {
        std::cout << "ERROR!!!" << std::endl;
    }
}

Cesar::~Cesar()
{
    fin.close();
    fout.close();
}
void Cesar::setKey(int key)
{
    m_key = key;
}

int Cesar::getKey() const
{
    return m_key;
}

void Cesar::encrypt()
{
    std::string str = "";
    if(m_key == 1)
    {
        std::cin>>str;
        Cesar::fin<<str;
    }
    else{
        
    }
    while (!fin.eof())
    {
        std::string tmp = "";
        std::getline(fin, tmp);
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            {
                if ((tmp[i] - m_key) < 'A')
                {
                    str += char((tmp[i] - m_key) + 26);
                }
                else
                {
                    str += char(tmp[i] - m_key);
                }
            }
            else if (tmp[i] >= 'a' && tmp[i] <= 'z')
            {
                if ((tmp[i] - m_key) < 'a')
                {
                    str += char((tmp[i] - m_key) + 26);
                }
                else
                {
                    str += char(tmp[i] - m_key);
                }
                fout << str;
                str = "";
            }
        }
    }
}

void Cesar::decrypt()
{
    std::string str = "";
    while (!fout.eof())
    {
        std::string tmp = "";
        std::getline(fout, tmp);
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            {
                if ((tmp[i] - m_key) > 'z')
                {
                    str += char((tmp[i] + m_key) - 26);
                }
                else
                {
                    str += char(tmp[i] + m_key);
                }
            }
            else if (tmp[i] >= 'a' && tmp[i] <= 'z')
            {
                if ((tmp[i] + m_key) > 'z')
                {
                    str += char((tmp[i] + m_key) - 26);
                }
                else
                {
                    str += char(tmp[i] + m_key);
                }
                fin << str;
                str = "";
            }
        }
    }
}

int main()
{
    Cesar cs;
    cs.setKey(3);
    cs.encrypt();
    cs.decrypt();
    

   
   
}