//
// Created by Alex Dol on 28.11.2022.
//

#pragma once

#include "Array.h"
#include "Network.h"

class RNN {
public:
    Array<char> Alphabet;
    const char* alph;
    const char* cstr0;

    Network* net;

    RNN(const char* _alph, const char* _cstr0);

    void Run();
    Array<DataSet*> Memorize(Array<DataSet*> dsl, List<char> str);
    char* Retrieve(List<char> str);
    char Evaluate(Array<float> vin);
private:
    int MaxLast(Array<float> list);
};
