---
title: cuda及nvidia驱动安装
date: 2018-02-26 16:44:11
categories:
- 工具
tags:
- cuda
- nvidia
---

#cuda及nvidia驱动安装

---
### 1. Install nvidia driver

- 1.1 ***dependences***

```
apt install dkms build-essential linux-headers-amd64(or linux-headers-$(uname -r))
dpkg --add-architecture i386
apt install lib32z1 lib32ncurses5
```

- 1.2 ***disable nouveau module(optional)***

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
- 1.3 ***execute installer***

```sh
service lightdm stop / service gdm3 stop
sh NVIDIA-Linux-x86_64-XX.run
```

### 2. Install cuda/cudnn

```sh
sh cuda_XX.run
echo "/usr/local/cuda/lib64">>/etc/ld.so.conf.d/libcuda.conf
ldconfig
```
# Issues #

+ ### *nvidia driver install*

1. 登录管理器循环登录问题

```
bios 安全登录问题
#./NVIDIA-xxx.run -no-x-check -no-nouveau-check -no-opengl-files
```

+ ### *cuda install*

1. Can't locate InstallUtils.pm in @INC
```
export PERL5LIB=.
```

