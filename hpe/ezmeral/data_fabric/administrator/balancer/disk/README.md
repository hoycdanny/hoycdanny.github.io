# Balancer

## Disk Space Balancer

Disk Space Balancer是以Container為最小單位移動到各個Storage Pool(SP)達到平衡Cluster Disk 使用空間，因此在規劃叢集時Storage Pool 建議保持平衡。Disk Space Balancer在預設的情況下會每兩分鐘檢查一次，並根據每個Storage Pool使用率分配到不同的Bin中，在Bin分為儲存率較低與儲存率較高。

### Disk Space Balancer會根據以下這兩個參數來作為資料搬移的依據。

* Utilization Level of a SP (單個Storage Pool利用率)= (SP 已使用空間 / SP 總空間)
* Cluster Average  (Cluster平均) = (所有SP 已使用空間 / 所有 SP 總空間)

### Bin分組依據

* Below Average => Utilization Level of a SP 0~60%
* Average       => Utilization Level of a SP 61~70%
* Above Average => Utilization Level of a SP 71~90%
* Overused      => Utilization Level of a SP 91~100%

### 搬移Container時選擇SP依據與限制。

* 兩個 `SP` 需來自相同的 `Topology` 
* 單一 `SP` 當時搬移的 `Container` 數量需小於等於2
* 搬移Container至某個 `SP` 後，導致該 `SP` 又須搬移 
* 同一節點的 `SP` 不互相搬移
* 來自同一個 `Bin` 不互相搬移
* 五分鐘前 `Container` 剛搬移將不複製與搬移
* 一分鐘前 `Container` 被刪除將不複製與搬移
* 該 `SP` 忙碌中 總資料量的2％正在傳出


### 範例：

```

(Storage Pool1) Disk 1TB * 3  (Utilization Level of a SP) => 0.33 = 1TB   / 3TB 
(Storage Pool2) Disk 1TB * 3  (Utilization Level of a SP) => 0.66 = 2TB   / 3TB
(Storage Pool3) Disk 1TB * 3  (Utilization Level of a SP) => 0.66 = 2TB   / 3TB
(Storage Pool4) Disk 1TB * 3  (Utilization Level of a SP) => 0.9  = 2.7TB / 3TB
(Storage Pool5) Disk 1TB * 3  (Utilization Level of a SP) => 0.8  = 2.4TB / 3TB
(Storage Pool6) Disk 1TB * 3  (Utilization Level of a SP) => 0.8  = 2.4TB / 3TB

Cluster Average => 0.69 = 12.5TB / 18TB 


Bin

Below Average => Storage Pool 1
Average       => Storage Pool 2-3
Above Average => Storage Pool 5-6
Overused      => Storage Pool 4


階段一：

'Overused' 與 'Above Average' 的Storage Pool 平衡

Storage Pool 4,5,6 平衡
(Storage Pool4) Disk 1TB * 3  (Utilization Level of a SP) => 0.83  = 2.5TB / 3TB
(Storage Pool5) Disk 1TB * 3  (Utilization Level of a SP) => 0.83  = 2.5TB / 3TB
(Storage Pool6) Disk 1TB * 3  (Utilization Level of a SP) => 0.83  = 2.5TB / 3TB

階段二：

'Below Average' 與 'Average' 的Storage Pool 平衡

Storage Pool 1,2,3 平衡
(Storage Pool1) Disk 1TB * 3  (Utilization Level of a SP) => 0.55 = 1.66TB / 3TB
(Storage Pool2) Disk 1TB * 3  (Utilization Level of a SP) => 0.55 = 1.66TB / 3TB
(Storage Pool3) Disk 1TB * 3  (Utilization Level of a SP) => 0.55 = 1.66TB / 3TB

階段三：

所有節點Storage Pool 1-6 平衡

(Storage Pool1) Disk 1TB * 3  (Utilization Level of a SP) => 0.694  = 2.08TB / 3TB
(Storage Pool2) Disk 1TB * 3  (Utilization Level of a SP) => 0.694  = 2.08TB / 3TB
(Storage Pool3) Disk 1TB * 3  (Utilization Level of a SP) => 0.694  = 2.08TB / 3TB
(Storage Pool4) Disk 1TB * 3  (Utilization Level of a SP) => 0.694  = 2.08TB / 3TB
(Storage Pool5) Disk 1TB * 3  (Utilization Level of a SP) => 0.694  = 2.08TB / 3TB
(Storage Pool6) Disk 1TB * 3  (Utilization Level of a SP) => 0.694  = 2.08TB / 3TB


```


### 如何配置

#### 使用 `MCS` 配置 `Disk Balancer`

Admin > Clusters Settings > Balancer

![](https://github.com/hoycdanny/hoycdanny.github.io/blob/master/hpe/ezmeral/data_fabric/administrator/balancer/disk/img/disk-balancer-mcs-gui.png?raw=true)


#### 參數說明：

##### Enabled：關閉與開啟 `Disk Balancer`

##### Disk Balancer Preset：

```
Disk Balancer Preset:
    Moderate (Default)
	Threshold — 70%
	Concurrent Disk Rebalancer — 10%
    Rapid
	Threshold — 50%
	Concurrent Disk Rebalancer — 5%
    Relaxed
	Threshold — 90%
	Concurrent Disk Rebalancer — 25%
```


##### Threshold：當 `SP`  使用率大於70%(預設值)開始搬移資料。

##### Concurrent Disk Rebalancer： 為了維持Cluster的效能與服務品質，因此僅會使用Cluster 10% 的 Node 數量資源來搬移資料。



#### MapR CLI：

#####  開啟與關閉 Disk Balancer 

```
maprcli config save -values {cldb.disk.balancer.enable:"1"}
```

##### 將 `Container` 移出`SP` 的閾值

```
maprcli config save -values {cldb.balancer.disk.threshold.percentage:"70"}
```

##### 限制 `Container` 搬移的次數最少會有 `1`

```
maprcli config save -values {cldb.balancer.disk.max.switches.in.nodes.percentage:"10"}
```

##### 等待平衡時間 預設1800秒

```
maprcli config save {"cldb.balancer.startup.interval.sec":"3600"} 
```

##### 每次運行平衡後可配置停止時間 預設120秒

```
maprcli config save {"cldb.balancer.disk.sleep.interval.sec":"300"}
```

##### 防止`Volume` 不平衡，例如該Volume檔案存放不多，可能僅只存在一個 `SP` 造成不平衡。

```
maprcli config save -values {"prevent.volume.skew.by.diskbalancer":"true"}
```

##### 調整`Bin` 大小

![](https://docs.datafabric.hpe.com/62/ClusterAdministration/images/DSBalancerSampleBins.png)
```
dbal.above.avg.bin.size
dbal.avg.bin.size
dbal.below.avg.bin.size
dbal.overused.bin.size
maprcli config save -values {"dbal.below.avg.bin.size":"10"}
```

##### 設定Overused Threshold

```
maprcli config save -values {"cldb.balancer.disk.overused.threshold":"95"}
```

##### 設定'Below Average' 與 'Average' 的Storage Pool 平衡時間

maprcli config save -values {"dbal.below.avg.bins.balancing.frequency":"360"}

##### 讀取 `Balancer` 狀態

```shell=
# maprcli dump balancerinfo
usedMB  fsid                 spid                              percentage  outTransitMB  inTransitMB  capacityMB
209     5567847133641152120  01f8625ba1d15db7004e52b9570a8ff3  1           0             0            15200
209     1009596296559861611  816709672a690c96004e52b95f09b58d  1           0             0            15200
```

```shell=
# maprcli dump balancerinfo -json
        ....
        {
        "containerid":7840,
        "sizeMB":15634,
        "From fsid":8081858704500413174,
        "From IP:Port":"10.50.60.64:5660-",
        "From SP":"9e649bf0ac6fb9f7004fa19d200abcde",
        "To fsid":3770844641152008527,
        "To IP:Port":"10.50.60.73:5660-",
        "To SP":"fefcc342475f0286004fad963f0fghij"
        }
```

##### 查看移動數量與大小

```shell=
# maprcli dump balancermetrics -json
{
  "timestamp":1337770325979,
  "status":"OK",
  "total":1,
  "data":[
    {
      "numContainersMoved":10090,
      "numMBMoved":3147147,
      "timeOfLastMove": "Wed May 23 03:51:44 PDT 2012"
    }
  ]
}
```

##### Balancer中可調整參數

```shell=
[root@datafabric01 ~]# maprcli config load -json | grep balancer
			"cldb.balancer.disk.deltaToRepopulateStoragePoolsBins":"5",
			"cldb.balancer.disk.deltatorepopulatestoragepoolsbins":"5",
			"cldb.balancer.disk.max.switches.in.nodes.percentage":"10",
			"cldb.balancer.disk.overused.threshold":"90",
			"cldb.balancer.disk.sleep.interval.sec":"120",
			"cldb.balancer.disk.threshold.percentage":"70",
			"cldb.balancer.role.max.switches.in.nodes.percentage":"10",
			"cldb.balancer.role.paused":"1",
			"cldb.balancer.role.skip.container.active.sec":"600",
			"cldb.balancer.role.sleep.interval.sec":"900",
			"cldb.balancer.startup.interval.sec":"1800",
			"cldb.disk.balancer.enable":"0",
			"cldb.role.balancer.logging.on":"0",
			"cldb.role.balancer.replicascount.tolerance":"1",
			"cldb.role.balancer.replicassize.tolerance":"15",
			"cldb.role.balancer.strategy":"BySize",
			"prevent.volume.skew.by.diskbalancer":"0",
```
