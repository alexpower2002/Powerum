#pragma once

#include "Array.h"
#include "Synapse.h"
#include "Network.h"
#include "Sigmoid.h"

class Synapse;

class Neuron
{
public:
	Array<Synapse*> InputSynapses;
	Array<Synapse*> OutputSynapses;

	int LastOutputSynapse;

	float Bias;
	float BiasDelta;
	float Gradient;
	float Value;

	Array<float> TempValues;
	Array<float> TempValues0;

	Neuron(bool isInput = false);
	Neuron(Array<Neuron*> inputNeurons);

	void InitializeOutputs();

	float CalculateValue();

	float CalculateGradient();
	float CalculateGradient(float target);

	void UpdateWeights(float learnRate, float momentum);
};