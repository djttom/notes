# Table of Content
1. [Overview](#vverview)
2. [Kernel](#kernel)
3. [Device Driver](#device-driver)
4. [Linux Environment](#environment)
   1. [shared libraries](shared-libraries) [udev](#udev)
5. [Linux Commands](#linux-command)
   1. [df du](#df-du) [tar](#tar)
   2. [cp scp rsync](#cp-scp-rsync) [find grep xargs](#find-grep-xargs)

# Overview
In linux, everyting is a file.

# Kernel 

# Device Driver 

# Linux Environment 
## Shared Libraries
[Shared Libraries search orders:](https://amir.rachum.com/blog/2016/09/17/shared-libraries/)
1. directories listed in the executable’s `rpath`.
2. directories in the `LD_LIBRARY_PATH` environment variable, which contains colon-separated list of directories (e.g., /path/to/libdir:/another/path)
3. directories listed in the executable’s `runpath`.
4. list of directories in the file `/etc/ld.so.conf`. This file can include other files, but it is basically a list of directories - one per line.
5. Default system libraries - usually `/lib` and `/usr/lib` (skipped if compiled with -z nodefaultlib

The env **LD_LIBRARY_PATH** is a colon-separated set of directories where libraries should be searched for first, before the standard set of directories

The command **`ldd <elf or obj>`** is used to print out shared object dependencies.

## udev
The udev is the device manager for linux kernel that creates/removes device nodes in the `/dev` directory dynamically. It runs in userspace and the user can change device names using udev rules. [Introduction to device management](https://www.linux.com/news/udev-introduction-device-management-modern-linux-system/)  
When a device is added or removed, kernel events are produced which will notify udev in user space.  
The udev needs the kernel configs `CONFIG_HOTPLUG/NET/UNIX/SYSFS/PROC_FS/TEMPFS/INOTIFY/SIGNALFD=y`  
The udev depends on the proc and sys file systems and they must be mounted on `/proc` and `/sys`  

### Kernel device event management
1. when bootup is initialized, the `/dev` directory is mounted in tmpfs: `sudo mount -t tmpfs udev /dev`.
2. The `/dev` directory is populated with the static device nodes from `/lib/udev/devices`.
3. The udev daemon is started. It listens and collects uevents from the kernel netlink socket for all devices connected to the system.
4. The udev daemon will parse the uevent data and match the data with rules specified in `/etc/udev/rules.d`, create the device nodes and symbolic links for the devices as specified in the rules.
5. The udev daemon reads the rules from `/etc/udev/rules.d/*.rules` and stores them in the memory. whenever rules are added/removed/modified, udevd receives an inotify event, it will read the changes and updates the memory.

udev files 
```
/dev/*                       # created device files
/lib/udev/*                  # helper programs called from udev rules 
/lib/udev/devices/*          # static /dev content
/lib/udev/rules.d/*.rules    # standard udev event matching rules               
                                                                                
/etc/udev/*                                                                     
/etc/udev/udev.conf          # udev config file                                 
/etc/udev/mount.backlist                                                                                
/etc/udev/rules.d/*.rules    # local/custom udev event matching rules 
```

The linux command utility `udevadm` is created to manage devices and nodes in a system.
```
udevadm [--debug] [--version] [--help]
udevadm command [options] 
command: info, trigger, settle, control, monitor, test

$> udevadm info -a -p /sys/class/net/eth0/
```

# Linux Commands <a name="LinuxCommand"></a>
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

### cp scp rsync
both for remote and local copy files.  
scp: less optimize and speed, more secure (use ssh). use scp for simple day to day work.   
rsync: optimize and speed, less secure (similar to plain http), more secure with `--rsh=ssh`; provides more options; use delta transfer algorithm if dest already exists; transfer and replace whole file; copy symlinks as symlinks with option `-l`.  
```
scp -r tom@www.myserver.com:/user/document /root/tom

rsync -avz ... 
-a is archive mode same as: -rlptgoD, is recursive, symlinks, preserve permissions, group, owner, devices, ...
-v is verbose; -z is compress during transfer;

rsync -rlptzv --delete --exclude='.git' --exclude="*.o" --exclude="*.Td" --exclude="*.a" --exclude="__pycache__" --progress "tom@myserver.com:/nobackup/tom/code /root/tom/code
--progress to show progress during transfer 
--delete to delte extra files from dest dirs.
--exclude=PATTERN to exclude files matching pattern;

cp -av
-a is archive mode same as: -dR --preserve=all
-v is verbose; -r|-R is copy recursively
```

### find grep xargs
```
# search pattern in all files under the_directory
grep -r pattern the_directory

# search pattern in all files from find output of list of files
find . -name "*.[ch]" | xargs grep pattern
```
