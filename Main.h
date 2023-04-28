#pragma once

#include "Array.h"
#include "UIProgressBarChart.h"
#include "MMU.h"
#include "UIGrid.h"
#include "UILabel.h"
#include "Random.h"
#include "Network.h"
#include "IDT.h"
#include "Exceptions.h"
#include "RNN.h"
#include "UIImage.h"
#include "Paging.h"
#include "Graphics.h"
#include "PCI.h"

class Main
{
public:
	static void Start();
	static void NeuralNetwork();
	static void LetterOccurences();
	static void MemoryUsed();
	static void BatteryUsage();
	static void Files();
};