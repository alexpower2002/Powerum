#pragma once

#include "Array.h"
#include "Neuron.h"
#include "DataSet.h"
#include "Random.h"
#include "MMU.h"
#include "String.h"
#include "UILabel.h"

class Neuron;

class Network
{
public:
	float LearnRate;
	float Momentum;

	Array<Neuron*> InputLayer;
	Array<Array<Neuron*>> HiddenLayers;
	Array<Neuron*> OutputLayer;

	Network();
	Network(int inputSize, Array<int> hiddenSizes, int outputSize, float learnRate = 0.4, float momentum = 0.9);

	Array<float> TempAbsValues;

	void Train(Array<DataSet*> dataSets, int numEpochs);
	void Train(Array<DataSet*> dataSets, double minimumError);
	void ForwardPropagate(Array<float> inputs);
	void BackPropagate(Array<float> targets);
	Array<float> Compute(Array<float> inputs);
	float CalculateError(Array<float> targets);
	static float GetRandom();
};