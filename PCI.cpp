//
// Created by Alex Dol on 08.01.2023.
//

#include "PCI.h"

void PCI::AddDevice(PCIDevice pdev)
{
    pci_devices[devs] = pdev;
    devs++;
    return;
}

unsigned short PCI::ReadWord(unsigned short bus, unsigned short slot, unsigned short func, unsigned short offset)
{
    unsigned long address;
    unsigned long lbus = (unsigned long)bus;
    unsigned long lslot = (unsigned long)slot;
    unsigned long lfunc = (unsigned long)func;
    unsigned short tmp = 0;

    address = (unsigned long)((lbus << 16) | (lslot << 11) | (lfunc << 8) | (offset & 0xfc) | ((unsigned int)0x80000000));
    Ports::WriteInt(0xCF8, address);
    tmp = (unsigned short)((Ports::ReadInt(0xCFC) >> ((offset & 2) * 8)) & 0xffff);
    return (tmp);
}

unsigned short PCI::GetVendorID(unsigned short bus, unsigned short device, unsigned short function)
{
    unsigned int r0 = ReadWord(bus,device,function,0);
    return r0;
}

unsigned short PCI::GetDeviceID(unsigned short bus, unsigned short device, unsigned short function)
{
    unsigned int r0 = ReadWord(bus,device,function,2);
    return r0;
}

unsigned short PCI::GetClassID(unsigned short bus, unsigned short device, unsigned short function)
{
    unsigned int r0 = ReadWord(bus,device,function,0xA);
    return (r0 & ~0x00FF) >> 8;
}

unsigned short PCI::GetSubClassID(unsigned short bus, unsigned short device, unsigned short function)
{
    unsigned int r0 = ReadWord(bus,device,function,0xA);
    return (r0 & ~0xFF00);
}

void PCI::Probe()
{
    for(unsigned int bus = 0; bus < 256; bus++)
    {
        for(unsigned int slot = 0; slot < 32; slot++)
        {
            for(unsigned int function = 0; function < 8; function++)
            {
                unsigned short vendor = GetVendorID(bus, slot, function);
                
                if(vendor == 0xffff) continue;
                
                unsigned short device = GetDeviceID(bus, slot, function);
                
                PCIDevice pdev = PCIDevice();
                pdev.vendor = vendor;
                pdev.device = device;
                pdev.func = function;

                AddDevice(pdev);
            }
        }
    }
}

unsigned short PCI::CheckVendor(unsigned short bus, unsigned short slot)
{
    unsigned short vendor, device;
    /* check if device is valid */
    if ((vendor = ReadWord(bus,slot,0,0)) != 0xFFFF) {
        device = ReadWord(bus,slot,0,2);
        /* valid device */
    } return (vendor);
}

void PCI::Initialize()
{
    devs = 0;
    pci_devices = new PCIDevice[32];

    Probe();
}
