---
title: Tips of Git
date: 2018-02-27 17:30:59
categories:
- 工具
- Git
tags:
- Git
- GitHub
---

# Tips of Git

---

+ ### delete submodule

```bash
$ git rm the_submodule
$ rm -rf .git/modules/the_submodule
```

+ ### ignore submodule

```bash
$ echo "sub_repo/" >> .gitignore
$ git clone https://user@bitbucket.org/user/repo.git sub_repo   
```