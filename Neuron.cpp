#include "Neuron.h"

Neuron::Neuron(bool isInput)
{
	Bias = 0;
	BiasDelta = 0;
	Gradient = 0;
	Value = 0;

	LastOutputSynapse = 0;

    if(!isInput)
    {
        TempValues = Array<float>(InputSynapses.Count);
    }
}

Neuron::Neuron(Array<Neuron*> inputNeurons)
{
	Bias = 0;
	BiasDelta = 0;
	Gradient = 0;
	Value = 0;
	
	InputSynapses = Array<Synapse*>(inputNeurons.Count);
	
	LastOutputSynapse = 0;

	for (int i = 0; i < inputNeurons.Count; i++)
	{
		auto synapse = new Synapse(inputNeurons[i], this);

        inputNeurons[i]->OutputSynapses[inputNeurons[i]->LastOutputSynapse] = synapse;

        inputNeurons[i]->LastOutputSynapse++;

        InputSynapses[i] = synapse;
	}
	
	TempValues = Array<float>(InputSynapses.Count);
}

void Neuron::InitializeOutputs()
{
	TempValues0 = Array<float>(OutputSynapses.Count);
}

extern float Sum(Array<float> Elements);

float Neuron::CalculateValue()
{
	for (int i = 0; i < InputSynapses.Count; i++)
	{
        TempValues[i] = InputSynapses[i]->Weight * InputSynapses[i]->InputNeuron->Value;
	}

	Value = Sigmoid::Output(Sum(TempValues) + Bias);

	return Value;
}

float Neuron::CalculateGradient()
{
	for (int i = 0; i < OutputSynapses.Count; i++)
	{
        TempValues0[i] = OutputSynapses[i]->OutputNeuron->Gradient * OutputSynapses[i]->Weight;
	}

	Gradient = Sum(TempValues0) * Sigmoid::Derivative(Value);

	return Gradient;
}

float Neuron::CalculateGradient(float target)
{
	Gradient = (target - Value) * Sigmoid::Derivative(Value);

	return Gradient;
}

void Neuron::UpdateWeights(float learnRate, float momentum)
{
	float prevDelta = BiasDelta;

	BiasDelta = learnRate * Gradient;
	Bias += BiasDelta + momentum * prevDelta;

	for (int i = 0; i < InputSynapses.Count; i++)
	{
		prevDelta = InputSynapses[i]->WeightDelta;

        InputSynapses[i]->WeightDelta = learnRate * Gradient * InputSynapses[i]->InputNeuron->Value;
        InputSynapses[i]->Weight += InputSynapses[i]->WeightDelta + momentum * prevDelta;
	}
}