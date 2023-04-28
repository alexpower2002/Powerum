//
// Created by Alex Dol on 08.01.2023.
//

#pragma once

#include "Ports.h"

struct PCIDeviceID {
    unsigned int vendor;
    unsigned int device;
    unsigned int func;
};

struct PCIDevice {
    unsigned int vendor;
    unsigned int device;
    unsigned int func;
};

class PCI {
public:
    PCIDevice* pci_devices = 0;
    unsigned int devs = 0;

    void AddDevice(PCIDevice pdev);
    unsigned short ReadWord(unsigned short bus, unsigned short slot, unsigned short func, unsigned short offset);
    unsigned short GetVendorID(unsigned short bus, unsigned short device, unsigned short function);
    unsigned short GetDeviceID(unsigned short bus, unsigned short device, unsigned short function);
    unsigned short GetClassID(unsigned short bus, unsigned short device, unsigned short function);
    unsigned short GetSubClassID(unsigned short bus, unsigned short device, unsigned short function);
    void Probe();
    unsigned short CheckVendor(unsigned short bus, unsigned short slot);
    void Initialize();
};
