# Why Data Fabric Event Store


## HPE DataFabric-EventStore(ES)角色說明。

* 系統管理員
  * 安全性
  * 高可用性
  * 副本策略
  * 異地備援
  * 跨資料中心管理- ``, `單一介面`

* 系統開發者
  * Topic 交換訊息的邏輯單位
  * Producer 發布者
  * Consumer 消費者或稱訂閱者


### 系統管理員-安全性

* adminperm
* copyperm
* consumeperm
* produceperm
* topicperm

![Access Control Expression (ACE)](https://docs.datafabric.hpe.com/61/MapR_Streams/images/stream_policies_security_2.png)


### 系統管理員-Replication

* Basic Primary-Secondary Replication
* Many-to-One Replication
* Multi-Master Replication

#### Basic Primary-Secondary Replication

假設您的公司在 `nagoya` 名古屋設有工廠，並且該工廠有許多設備安裝了不同的 `Sensor` 提供多種分析指標。此案例 `Sensor` 的角色是 `Producer`，它們將 `Message` 發佈到名為 `Metrics` 的Stream 中。數據分析家或工廠的機械手臂則扮演著 `Consumers` 的角色，讀取訊息並加以分析或作為機械手臂操作的依據，以此案例得知該數據可作為日後的分析依據非常重要，因此且需備份至異地資料中心 `nagoya_ha`，此時將利用 `HPE DataFabric Replication` 的功能 創造兩個副本分別為 `Primary` & `Secondary` 。

![Basic Primary-Secondary Replication](https://docs.datafabric.hpe.com/61/MapR_Streams/images/cross_cluster_replication_scenario_3_revised_again.png)

#### Many-to-One Replication

假設您的公司總部在 `sanfrancisco` 在 `nagoya` 與 `kaesong` 有分公司，每間分公司都有產線2，則需要創建兩個Topic `line_2_nagoya` 和 `line_2_kaesong`

![Many-to-One Replication](https://docs.datafabric.hpe.com/61/MapR_Streams/images/replication_two_factories_to_sf_2_revised.png)

#### Multi-Master Replication

雙中心同步與複製 Topic 需要不同

![Multi-Master Replication](https://docs.datafabric.hpe.com/61/MapR_Streams/images/cross_cluster_replication_scenario_6_revised.png)

### Replication 模式

#### Asynchronous replication

當收到 `Producer` 的訊息已存到單一端 `Partdition` 後，即可提供給 `Consumers` 讀取。

#### Synchronous replication 

當收到 `Producer` 的訊息已複製到兩端 `Partdition` 後，才可提供給 `Consumers` 讀取。



## HPE DataFabric-EventStore(ES)各種應用案例:

* 物聯網
* Event pipelines
* Database change capture


## 效能測試

[kafka vs Mapr-ES](https://developer.hpe.com/blog/vyvg31gkBKH6DoBPk6Ov/kafka-vs-mapr-event-store-why-mapr0)


