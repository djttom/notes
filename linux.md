In linux, everyting is a file.

# Kernel

# Device Driver

# Linux Environment
## Shared Libraries
[HowTo Shared Libraries](https://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html).  
In a nutshell, when it's looking for a dynamic library (.so file) the linker tries:
- directories listed in the environment variable **LD_LIBRARY_PATH** (DYLD_LIBRARY_PATH on OSX);
- directories listed in the executable's `-rpath`, which is specified in linking;
- directories on the system search path, which consists of the entries in `/etc/ld.so.conf` plus `/lib` and `/usr/lib`

The env **LD_LIBRARY_PATH** is a colon-separated set of directories where libraries should be searched for first, before the standard set of directories

# Linux Commands
## Memory

## PCI
### lspci display pci device information
```
lspci -s [[[[<doman>]:]<bus>]:][<slot>[.[<func>]] -d [<vendor id>]:[<device id>][:<class id>]
      -t -m -mm -v -vv -vvv -x -xxx -xxxx -v -vv -n -nn

lspci -tv             # display all pci device tree with detail info
lspci -s 0:8.0 -vn    # display device on bus 0 slot 8 function 0
lspci -d 1137:a005    # display cisco silicon-one asic device
```
### setpci
```
setpci 
setpci -s 0:8.0 BASE_ADDRESS_0=0xf0000000
```
### rescan bus and remove a bus
```
echo 1 > /sys/bus/pci/rescan
echo 1 > /sys/bus/pci/devices/0000\:05:00.0/remove
```

## I2C
### i2cdetect
```
i2cdetect -y 3
```

## Miscs
### df du
```
df -h .
du -sh *
```

### service
The service command is to run a system V init script that is located under /etc/init.d/SCRIPT
```
service SCRIPT COMMAND [OPTIONS]
service --status-all
service --help | -h | --version

# search and start redist service
service redis
/etc/init.d/redis {start|stop|restart|force-reload}
/etc/init.d/redis start
```
### tar
Syntax usage
```
tar {A|c|d|r|t|u|x}[GnSkUWOmpsMBiajJzZhPlRvwo] [ARG...]
-c, --create, create a new archive file
-x, --extract, extract an archive file
-v, show progress of the archive file
-f, file name of the archive file
```
[Some examples](https://www.tecmint.com/18-tar-command-examples-in-linux/)
```
tar -cvf filename.tar <directory ...>        # create tar file
tar -cvzf filename.tar.gz <directory ...>    # create gzip tar file
tar -xvf filename.tar.gz.                    # extract gzip tar file
tar -t --list

# first extract a few folders from the compress tar file
tar -xvf dev-sdk-1.tar.gz dev-sdk-1/driver/include dev-sdk-1/driver/lib
# create a new compressed tar file with top directory name changed
tar -czvf dev-lib-1.tar.gz dev-sdk-1 --transform='s,^dev-sdk-1,dev-lib-1,'
```
