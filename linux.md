In linux, everyting is a file.

# Kernel

# Device Driver

# Linux Commands
## Memory

## PCI
### display pci device information
```
lspci -s [[[[<doman>]:]<bus>]:][<slot>[.[<func>]] -d [<vendor id>]:[<device id>][:<class id>]
      -t -m -mm -v -vv -vvv -x -xxx -xxxx -v -vv -n -nn

lspci -tv             # display all pci device tree with detail info
lspci -s 0:8.0 -vn    # display device on bus 0 slot 8 function 0
lspci -d 1137:a005    # display cisco silicon-one asic device
```
### set pci
```
setpci 
setpci -s 0:8.0 BASE_ADDRESS_0=0xf0000000
```
### rescan/enumerate pci bus, remove a bus
```
echo 1 > /sys/bus/pci/rescan
echo 1 > /sys/bus/pci/devices/0000\:05:00.0/remove
```

## I2C
```
i2cdetect -y 3
```
