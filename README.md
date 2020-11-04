<p align="center"><a href="#" target="_blank" rel="noopener noreferrer"><img width="100" src="logo.jpg" alt="LuatOS logo"></a></p>

[![license](https://img.shields.io/github/license/openLuat/LuatOS)](/LICENSE)

LuatOS是运行在嵌入式硬件,用户编写lua代码就可完成各种功能

1. 基于Lua 5.3.6
2. 低内存需求, 最低32kb, 96kb flash空间
3. 硬件抽象层兼容M3/arm/risc-v等
4. 可测试,可模拟(qemu)
5. 在线升级
6. 可裁剪,可扩展

----------------------------------------------------------------------------------

## 代码示例节选

做一个灯神(点亮并闪烁一个LED灯)

```lua
local sys = require("sys")

-- 把GPIO19设置为输出模式,上拉,初始电平为低电平(0代表低电平,1代表高电平)
local netled = gpio.setup(19, 0, gpio.PULLUP)

sys.taskInit(function()
    while 1 do
        netled(1) -- 输出高电平
        sys.wait(500) -- 等待500ms
        netled(0) -- 输出低电平
        sys.wait(500) -- 等待500ms
    end
end)

-- 主循环, 必须加
sys.run()
```

## 如何使用LuatOS

1. 首先, 购买开发板([Wifi](https://item.taobao.com/item.htm?id=590724913462) / [NB-IOT](https://item.taobao.com/item.htm?id=625893281770&ns=1))
2. 然后, 下载[固件包](https://gitee.com/openLuat/LuatOS/releases),按里面的文档进行刷机
3. 开始愉快地玩耍(或者放着积灰...)

有任何疑问? 加 **QQ群: 1061642968** , 很多大佬哦

----------------------------------------------------------------------------------
## 资源

* [临时官网](https://luatos.vue2.cn/)
* 参阅 [Luat 平台层](docs/markdown/core/luat_platform.md)
* [文档索引](docs.md)
* [搭建开发环境](docs/markdown/proj/workspace.md)
* [如何开发](docs/markdown/proj/how_to_dev.md)
* [预编译固件](https://github.com/openLuat/LuatOS/releases)
* [Lua 5.3中文手册](https://www.runoob.com/manual/lua53doc/)
* [合宙官网](http://www.openluat.com)
* [合宙商城](http://m.openluat.com)
* [联盛德W600/合宙Air640W专属说明](bsp/air640w/README.md)
* [合宙Air302专属说明](bsp/air302/README.md)
* [Lua API文档](docs/api/lua/README.md)

----------------------------------------------------------------------------------

## 使用到的开源项目

* [lua](https://www.lua.org/) Lua官网
* [rt-thread](https://github.com/RT-Thread/rt-thread) 国产rtos, 非常好用
* [rtt-ds18b20](https://github.com/willianchanlovegithub/ds18b20) 在RT-Thread环境下读取ds18b20
* [LuaTask](https://github.com/openLuat/Luat_2G_RDA_8955) 合宙LuaTask
* [iRTU](https://github.com/hotdll/iRTU) 基于Luat的DTU, 稀饭大神
* [airkissOpen](https://github.com/heyuanjie87/airkissOpen) 参考其实现思路
* [minmea](https://github.com/kosma/minmea) 解析nmea
* [u8g2_wqy](https://github.com/larryli/u8g2_wqy) u8g2的中文字体
* [printf](https://github.com/mpaland/printf) A printf / sprintf Implementation for Embedded Systems
* [YMODEM for Python](https://github.com/alexwoo1900/ymodem) YMODEM 用于下载脚本
* [elua](http://www.eluaproject.net/) eLua 虽然已经停更多年,但精神犹在

## 免费服务

* [NetLab](https://netlab.luatos.io/index.html) TCP/UDP透传调试,公网IP, HEX值收发, Tab式多客户端. [备用地址](https://netlab.luatos.io/index.html)
* [DevLog](udp://devlog.luatos.io:9072) 设备日志记录,格式兼容errDump.lua 查看日志请登录LuatOS官网.

## 更多项目

* [iRTU](https://gitee.com/hotdll/iRTU) 开源DTU/RTU解决方案
* [Luat_CSDK_Air724U](https://gitee.com/openLuat/Luat_CSDK_Air724U) 市面上最畅销的4G Cat.1模块的开发包
* [llcom](https://github.com/chenxuuu/llcom) 可运行lua脚本的高自由度串口调试工具
* [irtu-gps](https://gitee.com/wendal/irtu-gps) 基于iRTU项目,实现GPS数据的接收和展示


## 总体架构

![总体架构](system.jpg)

## 授权协议

[MIT License](LICENSE)
