---
title: 从感知机到MLP
date: 2018-02-26 16:52:33
categories:
- 机器学习
- 神经网络
tags:
- 感知机
- 反向传播
- Delta准则
---

# 从感知机到MLP

## M-P神经元

1943年，McCulloch和Walter Pitts提出了 M-P神经元（Mcculloch-Pitts Neuron）模型[1]。MP模型有不同的描述方式，大体上分为两类，一类为神经元之间连接的边带权值，另一类为神经元连接的边不带权值，两者是等价的。
McCulloch–Pitts神经元输入输出数据均为二值0或1，对应神经元的抑制/激活，即$x \in \{0,1\}, y \in \{0,1\}$。

* M-P神经元结构
    M-P神经元与网络结构如下图所示，输入数据可以分为两类，一类为激活输入（连接边端点实心圆点），一类为抑制输入（连接边端点空心圆点）[2]。

    ![M-P_unit](M-P_unit.png) ![M-P_diagram_unweighted](M-P_diagram_unweighted.png)

    上述抑制输入为绝对抑制输入，即存在任意一条抑制输入生效（对应x=1）时，神经元输出为0（抑制）;反之，当不存在抑制输入边或者所有抑制输入均失效（对应x均为0）时，则根据激活输入边的数量，将所有生效的输入求和，并进行阈值判断，大于阈值则神经元激活，输出1，否则输出0。如下所述：

    $$
        output=
        \begin{cases}
            1,        &\text{$\sum_i x_i \geq \theta$ AND no inhibition}\\
            0,    &\text{otherwise}
        \end{cases} \tag{1}
    $$

* 等价的有权值神经元结构

    通过将神经元连接边加入权值可以简化网络描述与定义，如下所示：首先分析激活输入单元的简化，如下图所示，有权值（有理数）的网络和无权值的网络等价[2]。
    $0.2x_1+0.4x_2 +0.3x_3 \geq 0.7 \Longleftrightarrow 2x_1+4x_2+3x_3 \geq 7$

    ![weighted_unit](weighted_unit.png) ![unweighted_unit](unweighted_unit.png)

    接下来简化抑制输入，设神经元每个抑制输入边权值为$p_j$，所有神经元激活输入边权值之和为$\sum_i w_i$，则对于任意$p_j$存在$\sum_i w_i + p_j \lt \theta$，因此对于任意$p_j$满足$p_j \lt \theta - \sum_i w_i$时，神经元的抑制输入边简化为权值为p的有权值输入边。式(1)等价于：

    $$
        output=
        \begin{cases}
            1,        &\text{$\sum_i w_ix_i \geq \theta$}\\
            0,    &\text{$\sum_i w_ix_i \lt \theta$}
        \end{cases}\tag{2}
    $$

M-P神经元组成的网络输入输出均为0或1，网络的结构（神经元边权值）与神经元阈值为初始固定设置，无法学习调整参数，通过修改调整网络连接方式和神经元阈值来学习不同的模式。

## 感知机

1958年，Frank Rosenblatt提出感知机（Perceptron）模型[3]。感知机在上述有权值M-P神经元模型基础上加入了参数学习准则，可以通过学习准则更新网络参数来进行有监督学习。感知机网络流程如下所示:

![perceptron_flow](perceptron_flow.png)


### Reference

[1] McCulloch W S, Pitts W. A logical calculus of the ideas immanent in nervous activity[J]. The bulletin of mathematical biophysics, 1943, 5(4): 115-133.
[2] Rojas R. Neural networks: a systematic introduction[M]. Springer Science & Business Media, 2013.
[3] Rosenblatt F. The perceptron, a perceiving and recognizing automaton Project Para[M]. Cornell Aeronautical Laboratory, 1957.
