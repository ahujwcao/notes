# Caffe Install for Debian/Ubuntu
### 1. System Install(amd64)

### 2. Install Dependences
```bash
apt install gcc g++ make cmake cmake-curses-gui
apt install libprotobuf-dev libleveldb-dev libsnappy-dev libopencv-dev libhdf5-serial-dev protobuf-compiler libgflags-dev libgoogle-glog-dev liblmdb-dev
apt install --no-install-recommends libboost-all-dev
apt install libatlas-base-dev
apt install python-dev python-skimage python-protobuf python-opencv
```

### 3. Install nvidia driver
- 3.1 ***dependences***
```
apt install dkms build-essential linux-headers-amd64(or linux-headers-$(uname -r))
dpkg --add-architecture i386
apt install lib32z1 lib32ncurses5
```
- 3.2 ***disable nouveau module(optional)***
+ vim /etc/modprobe.d/blacklist-nouveau.conf
```sh
blacklist nouveau
blacklist lbm-nouveau
options nouveau modeset=0
alias nouveau off
alias lbm-nouveau off
```
+ disable module
```sh
echo options nouveau modeset=0 | sudo tee -a /etc/modprobe.d/nouveau-kms.conf
update-initramfs -u
```
- 3.3 ***execute installer***
```sh
service lightdm stop / service gdm3 stop
sh NVIDIA-Linux-x86_64-XX.run
```
### 4. Install cuda/cudnn
```sh
sh cuda_XX.run
echo "/usr/local/cuda/lib64">>/etc/ld.so.conf.d/libcuda.conf
ldconfig
```
### 5. Compile Caffe

# Issues #
+ ### *cuda install*
1. Can't locate InstallUtils.pm in @INC
```
export PERL5LIB=.
```
+ ### *compile caffe*
2. Can't find hdf5
```
add path "/usr/include/hdf5/serial/","/usr/lib/x86_64-linux-gnu/hdf5/serial/" in Makefile.config
```
3. undefined reference to ‘H5LTget_dataset_ndims’xx
```
vim cmake/Dependencies.cmake to append ${HDF5_HL_LIBRARIES}
```
4. ***gcc/g++ version conflict***

- such as undefined reference to `google::base::CheckOpMessageBuilder::NewString[abi:cxx11]()'

```sh
## compile glog manually
apt purge libgoogle-glog-dev libgoogle-glog0v5
apt source libgoogle-glog-dev
cd google-glog-0.3.4
./configure

vim Makefile
#change line 613 to ACLOCAL=aclocal-1.15
#change line 619 to AUTOMAKE=automake-1.15
make
automake --add-missing
make -j 16
make install
```
