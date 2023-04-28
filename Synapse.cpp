#include "Synapse.h"

Synapse::Synapse()
{
	Weight = 0;
	WeightDelta = 0;
}

Synapse::Synapse(Neuron* inputNeuron, Neuron* outputNeuron)
{
	InputNeuron = inputNeuron;
	OutputNeuron = outputNeuron;
	Weight = Network::GetRandom();
	WeightDelta = 0;
}