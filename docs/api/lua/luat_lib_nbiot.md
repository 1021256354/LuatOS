---
module: nbiot
summary: NB-IOT操作库
version: V0001
date: 2020.04.30
---

--------------------------------------------------
# nbiot.isReady

```lua
nbiot.isReady()
```

网络是否就绪

## 参数表

> 无参数

## 返回值

> `boolean`: 已联网返回true,否则返回false

## 调用示例

```lua
-- 判断是否已经联网
if nbiot.isReady() then 
    log.info("nbiot", "net is ready")
end
```


--------------------------------------------------
# nbiot.imsi

```lua
nbiot.imsi()
```

读取IMSI

## 参数表

> 无参数

## 返回值

> `string`: 返回IMSI值，如果不存在就返回nil

## 调用示例

```lua
-- 读取imsi
log.info("nbiot", "imsi", nbiot.imsi())
```


--------------------------------------------------
# nbiot.iccid

```lua
nbiot.iccid()
```

读取ICCID

## 参数表

> 无参数

## 返回值

> `string`: 返回ICCID值，如果不存在就返回nil

## 调用示例

```lua
-- 读取iccid
log.info("nbiot", "iccid", nbiot.iccid())
```


--------------------------------------------------
# nbiot.imei

```lua
nbiot.imei(val)
```

读取或设置IMEI

## 参数表

Name | Type | Description
-----|------|--------------
`val`|`string`| 传入需要设置的imei值，不传就是读取

## 返回值

> `string`: 返回imei值，如果不存在就返回nil

## 调用示例

```lua
-- 读取imei
log.info("nbiot", "imei", nbiot.imei())
-------------------------
-- 设置imei
log.info("nbiot", "imei", nbiot.imei("898989898989899898"))
```


--------------------------------------------------
# nbiot.rssi

```lua
nbiot.rssi()
```

读取RSSI

## 参数表

> 无参数

## 返回值

> `int`: 返回rssi值

## 调用示例

```lua
-- 读取rssi
log.info("nbiot", "rssi", nbiot.rssi())
```


--------------------------------------------------
# nbiot.apn

```lua
nbiot.apn()
```

读取APN

## 参数表

> 无参数

## 返回值

> `string`: 返回apn值

## 调用示例

```lua
-- 读取APN
log.info("nbiot", "apn", nbiot.apn())
```


--------------------------------------------------
# nbiot.tac

```lua
nbiot.tac()
```

读取TAC

## 参数表

> 无参数

## 返回值

> `int`: 返回TAC值

## 调用示例

```lua
-- 读取TAC
log.info("nbiot", "tac", nbiot.tac())
```


--------------------------------------------------
# nbiot.tacTime

```lua
nbiot.tacTime()
```

读取Tac Time

## 参数表

> 无参数

## 返回值

> `int`: 返回Tac Time值

## 调用示例

```lua
-- 读取Tac Time
log.info("nbiot", "tac time", nbiot.tacTime())
```


--------------------------------------------------
# nbiot.activeTime

```lua
nbiot.activeTime()
```

读取Active Time

## 参数表

> 无参数

## 返回值

> `int`: 返回Active Time值

## 调用示例

```lua
-- 读取Active Time
log.info("nbiot", "Active Time", nbiot.activeTime())
```


--------------------------------------------------
# nbiot.cellID

```lua
nbiot.cellID()
```

读取CellID

## 参数表

> 无参数

## 返回值

> `int`: 返回CellID值

## 调用示例

```lua
-- 读取CellID
log.info("nbiot", "CellID", nbiot.cellID())
```


--------------------------------------------------
# nbiot.snr

```lua
nbiot.snr()
```

读取SNR

## 参数表

> 无参数

## 返回值

> `int`: 返回SNR值

## 调用示例

```lua
-- 读取SNR
log.info("nbiot", "SNR", nbiot.snr())
```


--------------------------------------------------
# nbiot.csq

```lua
nbiot.csq()
```

读取CSQ, 并不完全等价于GSM的CSQ

## 参数表

> 无参数

## 返回值

> `int`: 返回csq值

## 调用示例

```lua
-- 读取csq
log.info("nbiot", "csq", nbiot.csq())
```


--------------------------------------------------
# nbiot.ceLevel

```lua
nbiot.ceLevel()
```

读取CE Level

## 参数表

> 无参数

## 返回值

> `int`: 返回CE Level值

## 调用示例

```lua
-- 读取CE Level
log.info("nbiot", "CE Level", nbiot.ceLevel())
```


--------------------------------------------------
# nbiot.sn

```lua
nbiot.sn(val)
```

读取或设置SN,普通刷机(刷底层/刷脚本)不会清除

## 参数表

Name | Type | Description
-----|------|--------------
`val`|`string`| 需要设置的SN值(只能是可见字符),不传值则为读取

## 返回值

> `string`: 返回SN值

## 调用示例

```lua
-- 读取SN
log.info("nbiot", "SN", nbiot.sn())
-------------------------
-- 设置SN
log.info("nbiot", "SN", nbiot.sn("My Custom SN"))
```


--------------------------------------------------
# nbiot.updateCellInfo

```lua
nbiot.updateCellInfo()
```

刷新网络信息,可通过定时任务刷新,最小间隔5秒

## 参数表

> 无参数

## 返回值

> `boolean`: 成功启动刷新线程返回true，否则返回false.

## 调用示例

```lua
-- 刷新网络信息
nbiot.updateCellInfo()
sys.waitUntil("CELL_INFO_IND", 3000)
log.info("nbiot", "cell", json.encode(nbiot.getCellInfo()))
```


--------------------------------------------------
# nbiot.mcc

```lua
nbiot.mcc()
```

读取MCC值,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `int`: 运营商MCC值

## 调用示例

```lua
-- 读取MCC
log.info("nbiot", "mcc", nbiot.mcc())
```


--------------------------------------------------
# nbiot.mnc

```lua
nbiot.mnc()
```

读取MNC值,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `int`: 运营商MNC值

## 调用示例

```lua
-- 读取MNC
log.info("nbiot", "mnc", nbiot.mnc())
```


--------------------------------------------------
# nbiot.earfcn

```lua
nbiot.earfcn()
```

读取earfcn值,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `int`: 运营商earfcn值

## 调用示例

```lua
-- 读取earfcn
log.info("nbiot", "earfcn", nbiot.earfcn())
```


--------------------------------------------------
# nbiot.phyCellId

```lua
nbiot.phyCellId()
```

读取phyCellId值,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `int`: 运营商phyCellId值

## 调用示例

```lua
-- 读取phyCellId
log.info("nbiot", "phyCellId", nbiot.phyCellId())
```


--------------------------------------------------
# nbiot.rsrq

```lua
nbiot.rsrq()
```

读取rsrq值,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `int`: 运营商ersrq值

## 调用示例

```lua
-- 读取rsrq
log.info("nbiot", "rsrq", nbiot.rsrq())
```


--------------------------------------------------
# nbiot.rsrp

```lua
nbiot.rsrp()
```

读取rsrp值,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `int`: 运营商rsrp值

## 调用示例

```lua
-- 读取rsrp
log.info("nbiot", "rsrp", nbiot.rsrp())
```


--------------------------------------------------
# nbiot.powerLevel

```lua
nbiot.powerLevel()
```

读取PowerLevel值,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `int`: 运营商PowerLevel值

## 调用示例

```lua
-- 读取PowerLevel
log.info("nbiot", "PowerLevel", nbiot.powerLevel())
```


--------------------------------------------------
# nbiot.getCellInfo

```lua
nbiot.getCellInfo()
```

获取网络基站详情,注册网络后可用,通过nbiot.updateCellInfo()刷新

## 参数表

> 无参数

## 返回值

> `table`: 网络基站详情

## 调用示例

```lua
-- 读取基站信息
log.info("nbiot", "cell info", json.encode(nbiot.getCellInfo()))
```


--------------------------------------------------
# nbiot.setCFUN

```lua
nbiot.setCFUN(val)
```

进入或退出飞行模式

## 参数表

Name | Type | Description
-----|------|--------------
`val`|`int`| 0飞行模式,1普通联网模式

## 返回值

> `boolean`: 设置成功返回true,否则返回false

## 调用示例

```lua
-- 进入飞行模式
nbiot.setCFUN(0)
```


--------------------------------------------------
# nbiot.setBootCFUN

```lua
nbiot.setBootCFUN(val)
```

设置设备上电启动时，是否进入飞行模式

## 参数表

Name | Type | Description
-----|------|--------------
`val`|`int`| 0飞行模式,1普通联网模式

## 返回值

> `boolean`: 设置成功返回true,否则返回false

## 调用示例

```lua
-- 设置为上电进入飞行模式
nbiot.setBootCFUN(0)
```


--------------------------------------------------
# nbiot.getBootCFUN

```lua
nbiot.getBootCFUN(val)
```

获取设备上电启动时，是否进入飞行模式

## 参数表

Name | Type | Description
-----|------|--------------
`val`|`null`| *无*

## 返回值

> `int`: 开机就进入飞行模式返回0,进入普通模式返回1

## 调用示例

```lua
-- 获取上电模式
nbiot.getBootCFUN()
```

