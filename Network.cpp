#include "Network.h"

Random* rnd;

Network::Network(int inputSize, Array<int> hiddenSizes, int outputSize, float learnRate, float momentum)
{
	LearnRate = learnRate;
	Momentum = momentum;

	InputLayer = Array<Neuron*>(inputSize);

	for (int i = 0; i < inputSize; i++)
	{
        InputLayer[i] = new Neuron(true);

        InputLayer[i]->OutputSynapses = Array<Synapse*>(hiddenSizes[0]);

        InputLayer[i]->InitializeOutputs();
	}

	HiddenLayers = Array<Array<Neuron*>>(hiddenSizes.Count);

	auto firstHiddenLayer = Array<Neuron*>(hiddenSizes[0]);

	for (int i = 0; i < firstHiddenLayer.Count; i++)
	{
        firstHiddenLayer[i] = new Neuron(InputLayer);
	}

	for (int i = 0; i < hiddenSizes[0]; i++)
	{
		if (hiddenSizes.Count > 1)
		{
            firstHiddenLayer[i]->OutputSynapses = Array<Synapse*>(hiddenSizes[1]);

            firstHiddenLayer[i]->InitializeOutputs();
		}
		else
		{
            firstHiddenLayer[i]->OutputSynapses = Array<Synapse*>(outputSize);

            firstHiddenLayer[i]->InitializeOutputs();
		}
	}

    HiddenLayers[0] = firstHiddenLayer;

	for (int i = 1; i < hiddenSizes.Count; i++)
	{
		auto hiddenLayer = Array<Neuron*>(hiddenSizes[i]);

		for (int j = 0; j < hiddenSizes[i]; i++)
		{
            hiddenLayer[j] = new Neuron(HiddenLayers[i - 1]);
		}

		for (int j = 0; j < hiddenSizes[i]; i++)
		{
			if (hiddenSizes.Count > i + 1)
			{
                hiddenLayer[j]->OutputSynapses = Array<Synapse*>(hiddenSizes[i + 1]);

                hiddenLayer[j]->InitializeOutputs();
			}
			else
			{
                hiddenLayer[j]->OutputSynapses = Array<Synapse*>(outputSize);

                hiddenLayer[j]->InitializeOutputs();
			}
		}

        HiddenLayers[i] = hiddenLayer;
	}

	OutputLayer = Array<Neuron*>(outputSize);
	
	for (int i = 0; i < OutputLayer.Count; i++)
	{
        OutputLayer[i] = new Neuron(HiddenLayers[HiddenLayers.Count - 1]);
	}

	TempAbsValues = Array<float>(OutputLayer.Count);
}

void Network::Train(Array<DataSet*> dataSets, int numEpochs)
{
	for (int i = 0; i < numEpochs; i++)
	{
		for (int j = 0; j < dataSets.Count; j++)
		{
			ForwardPropagate(dataSets[j]->Values);
			BackPropagate(dataSets[j]->Targets);
		}
	}
}

float Sum(Array<float> Elements)
{
	float Result = 0;

	for (int i = 0; i < Elements.Count; i++)
	{
		Result += Elements[i];
	}

	return Result;
}

float Average(Array<float> Elements)
{
	return Sum(Elements) / Elements.Count;
}

const int max = 2147483647;

void Network::Train(Array<DataSet*> dataSets, double minimumError)
{
	double error = 1;
	int numEpochs = 0;

	auto errors = Array<float>(dataSets.Count);

	while (error > minimumError && numEpochs < max)
	{
		for (int i = 0; i < dataSets.Count; i++)
		{
			ForwardPropagate(dataSets[i]->Values);
			BackPropagate(dataSets[i]->Targets);

            errors[i] = CalculateError(dataSets[i]->Targets);
		}

		error = Average(errors);

		if ((numEpochs % 100) == 0)
		{
			//Print(error * 100);
		}

		numEpochs++;
	}
}

void Network::ForwardPropagate(Array<float> inputs)
{
	for (int i = 0; i < InputLayer.Count; i++)
	{
        InputLayer[i]->Value = inputs[i];
	}
	
	for (int i = 0; i < HiddenLayers.Count; i++)
	{
		for (int j = 0; j < HiddenLayers[i].Count; j++)
		{
            HiddenLayers[i][j]->CalculateValue();
		}
	}

	for (int i = 0; i < OutputLayer.Count; i++)
	{
        OutputLayer[i]->CalculateValue();
	}
}

void Network::BackPropagate(Array<float> targets)
{
	for (int i = 0; i < OutputLayer.Count; i++)
	{
        OutputLayer[i]->CalculateGradient(targets[i]);
	}
	
	for (int i = HiddenLayers.Count - 1; i >= 0; i--)
	{
		for (int j = 0; j < HiddenLayers[i].Count; j++)
		{
            HiddenLayers[i][j]->CalculateGradient();
		}
	}

	for (int i = HiddenLayers.Count - 1; i >= 0; i--)
	{
		for (int j = 0; j < HiddenLayers[i].Count; j++)
		{
            HiddenLayers[i][j]->UpdateWeights(LearnRate, Momentum);
		}
	}

	for (int i = 0; i < OutputLayer.Count; i++)
	{
        OutputLayer[i]->UpdateWeights(LearnRate, Momentum);
	}
}

Array<float> Network::Compute(Array<float> inputs)
{
	ForwardPropagate(inputs);

	auto outputs = Array<float>(OutputLayer.Count);

	for (int i = 0; i < OutputLayer.Count; i++)
	{
        outputs[i] = OutputLayer[i]->Value;
	}

	return outputs;
}

float Network::CalculateError(Array<float> targets)
{
	for (int i = 0; i < TempAbsValues.Count; i++)
	{
        TempAbsValues[i] = Math::abs(targets[i] - OutputLayer[i]->Value);
	}

	return Sum(TempAbsValues);
}

float Network::GetRandom()
{
	return 2 * ((float)rnd->Next(0, 1000000) / 1000000) - 1;
}