# trying_joy

![img](/img/1.gif)

![img](/img/2.png)

## 环境
Ubuntu 16.04

Ros knetic

Xbox one

## 说明
此文件为一个ros package，获取Xbox one按键信息并显示，即publisher获取joy信息，将对应的按键信息发送出去，subscriber显示出来。
下载后放在${workspace}/src下，编译后即可使用，如果是第一次用手柄，参考[这个网址](http://wiki.ros.org/joy/Tutorials/ConfiguringALinuxJoystick)进行设置

其中摇杆等连续变化的按键在较小幅度下会忽略，绝对值为0.3

具体对应信息如下：

![img](/img/3.png)

## 使用方法
设置好手柄后，打开三个终端，分别输入以下命令即可

`roscore`

`roslaunch trying_joy tj.launch`

`rosrun trying_joy sub`


