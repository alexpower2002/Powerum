#pragma once

#include "Neuron.h"

class Neuron;

class Synapse
{
public:
	Neuron* InputNeuron;
	Neuron* OutputNeuron;

	float Weight;
	float WeightDelta;

	Synapse();
	Synapse(Neuron* inputNeuron, Neuron* outputNeuron);
};