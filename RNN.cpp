//
// Created by Alex Dol on 28.11.2022.
//

#include "RNN.h"

RNN::RNN(const char* _alph, const char* _cstr0)
{
    alph = _alph;
    cstr0 = _cstr0;

    Alphabet = Array<char>(String::Length(alph));

    for (int i = 0; i < Alphabet.Count; i++)
    {
        Alphabet[i] = alph[i];
    }

    auto Sizes = Array<int>(1);

    Sizes[0] = Alphabet.Count;

    net = new Network(Alphabet.Count * 3, Sizes, Alphabet.Count);
}

void RNN::Run()
{
    auto str0 = List<char>();

    for (int i = 0; i < String::Length(cstr0); i++)
    {
        str0.Add(cstr0[i]);
    }

    str0.Add('0');
    str0.Add('0');

    auto dsl0 = Array<DataSet*>(String::Length(cstr0) - 2);

    dsl0 = Memorize(dsl0, str0);

    auto dsl = Array<DataSet*>(dsl0.Count);

    int dsli = 0;

    for (int i = 0; i < dsl0.Count; i++)
    {
        dsl[dsli] = dsl0[i];

        dsli++;
    }

    net->Train(dsl, 0.1);

    auto strm0 = List<char>();

    for (int i = 0; i < 3; i++)
    {
        strm0.Add(cstr0[i]);
    }

    auto vout = Retrieve(strm0);

    auto lbl0 = new UILabel(Point{ 200,200 }, vout);

    lbl0->Draw();
}

Array<DataSet*> RNN::Memorize(Array<DataSet*> dsl, List<char> str)
{
    auto first = str[0];
    auto second = str[1];
    auto third = str[2];
    auto forth = str[3];

    int index = 0;

    while (third != '0')
    {
        auto vin = Array<float>(Alphabet.Count * 3);
        auto vout = Array<float>(Alphabet.Count);

        auto trio = Array<char>(3);

        trio[0] = first;
        trio[1] = second;
        trio[2] = third;

        for (int i = 0; i < trio.Count; i++)
        {
            for (int j = 0; j < Alphabet.Count; j++)
            {
                if (trio[i] == '0')
                {
                    vin[i * Alphabet.Count + j] = 0;
                }
                else
                {
                    if (j == Alphabet.IndexOf(trio[i]))
                    {
                        vin[i * Alphabet.Count + j] = 1;
                    }
                    else
                    {
                        vin[i * Alphabet.Count + j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < Alphabet.Count; i++)
        {
            if (forth == '0')
            {
                vout[i] = 0;
            }
            else
            {
                if (i == Alphabet.IndexOf(forth))
                {
                    vout[i] = 1;
                }
                else
                {
                    vout[i] = 0;
                }
            }
        }

        first = second;
        second = third;
        third = forth;
        forth = str[index + 4];

        auto ds = new DataSet(vin, vout);

        dsl[index] = ds;

        index++;
    }

    return dsl;
}

char* RNN::Retrieve(List<char> str)
{
    auto result = str;

    auto first = result[0];
    auto second = result[1];
    auto third = result[2];

    while (!(third == '0' || result.Count == 32))
    {
        auto vin = Array<float>(Alphabet.Count * 3);

        auto trio = Array<char>(3);

        trio[0] = first;
        trio[1] = second;
        trio[2] = third;

        for (int i = 0; i < trio.Count; i++)
        {
            for (int j = 0; j < Alphabet.Count; j++)
            {
                if (trio[i] == '0')
                {
                    vin[i*Alphabet.Count + j] = 0;
                }
                else
                {
                    if (j == Alphabet.IndexOf(trio[i]))
                    {
                        vin[i*Alphabet.Count + j] = 1;
                    }
                    else
                    {
                        vin[i*Alphabet.Count + j] = 0;
                    }
                }
            }
        }

        first = second;
        second = third;
        third = Evaluate(vin);

        if (third != '0')
        {
            result.Add(third);
        }
    }

    char* c = new char[33]();

    for (int i = 0; i < result.Count; i++)
    {
        c[i] = result[i];
    }

    c[result.Count] = '\0';

    return c;
}

char RNN::Evaluate(Array<float> vin)
{
    auto vout = net->Compute(vin);

    char chr;

    int indexMax = MaxLast(vout);

    if (vout[indexMax] < 0.25)
    {
        chr = '0';
    }
    else
    {
        chr = Alphabet[indexMax];
    }

    return chr;
}

int RNN::MaxLast(Array<float> list)
{
    auto max = 0;

    for (int i = 0; i < list.Count; i++)
    {
        if (list[max] <= list[i]) {
            max = i;
        }
    }

    return max;
}
