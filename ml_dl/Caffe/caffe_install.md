---
title: Install Caffe
date: 2018-02-26 16:38:33
categories:
- Caffe
tags:
- 深度学习
- 框架部署
---

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

### 4. Install cuda/cudnn

### 5. Compile Caffe

# Issues #

+ ### *compile caffe*
1. Can't find hdf5

```
add path "/usr/include/hdf5/serial/","/usr/lib/x86_64-linux-gnu/hdf5/serial/" in Makefile.config
```
2. undefined reference to ‘H5LTget_dataset_ndims’xx

```
vim cmake/Dependencies.cmake to append ${HDF5_HL_LIBRARIES}
```

3. ***gcc/g++ version conflict***

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