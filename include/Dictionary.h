#ifndef DICTIONARY_H
#define DICTIONARY_H

class Verbete
{
};

class Dictionary
{
public:
    Dictionary(int n);
    int pesquisaDic(Dictionary *dic, Verbete *it);
    int insereDic(Dictionary *dic, Verbete *it);
    int imprimeDic(Dictionary *dic);
    int atualizaDic(Dictionary *dic, Verbete *it);
    int removeDic(Dictionary *dic, Verbete *it);
    int destroiDic(Dictionary *dic);
};
#endif