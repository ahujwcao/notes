---
title: 基于hexo和git的博客搭建
date: 2018-02-27 15:30:59
categories:
- 技术
- web
tags:
- Web
- hexo
- git
---

# 基于hexo和git的博客搭建

---

+ ### 安装依赖

    - #### [node.js](/2018/02/27/notes/tools/node.js/node/node.js_install/)

    - #### git 

    ```bash
    $ npm install hexo-deployer-git --save
    ```

+ ###  建站

```bash
$ hexo init <folder>
$ cd <folder>
$ npm install
```
+ ### 配置

修改站点配置文件_config.yml

```bash
deploy:
  type: git
  repo: git@github.com:ahujwcao/ahujwcao.github.io.git
```

+ ### 命令与基本操作

    - #### new
    
    ```bash
    $ hexo new [layout] <title>
    ```
    - #### generate

    ```bash
    $ hexo g
    ```

    - #### server
    
    ```bash
    $ hexo s
    ```
    - #### deploy

    ```bash
    $ hexo d
    ```
+ ### 域名绑定
申请域名，如阿里云，添加域名解析