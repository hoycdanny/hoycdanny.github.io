# Replication Role Balancer

Replication Role Balancer 是用來管理 `Container` 複製資料的優化包含以下：

* 複製過程中的 `網路頻寬`
* 服務讀取請求時的 `Disk I/O` 和 `CPU`

## `Container` 角色說明

* `Name Container` 角色分為 `Master` 與 `replica` 這兩個角色
* `Data Container` 角色分為 `Master` ｀ `Intermediate` 與 `Tail` 這三個角色

開啟 `Replication Role Balancer` 將用來確保每個角色的分配分散在各個節點中。

## 設置參數說明

* Concurrent Role Rebalancer : `Container` 當空間使用誤差超過多少%時觸發。
* Delay for Active Data in Seconds : 略過幾秒前處於 `Active` 狀態的資料。


## 可透過 `maprcli` 調整的參數
* cldb.balancer.role.paused => 0 啟動 1關閉
* cldb.role.balancer.strategy => `BySize` or `ByCount`
* cldb.balancer.role.max.switches.in.nodes.percentage => % 


```shell=
[root@datafabric01 ~]# maprcli dump rolebalancerinfo -json
{
	"timestamp":1613307989339,
	"timeofday":"2021-02-14 09:06:29.339 GMT+0800 PM",
	"status":"OK",
	"total":0,
	"data":[

	]
}
```
