# Auditing in HPE Data Fabric

使用Data Fabric，您可以記錄Cluster操作管理，以及對目錄、文件、串流和資料表格的操作保留Audit記錄。
HPE Data Fabric中的Auditing功能為企業提供可追朔的用戶行為。在企業的資料治理需求中，通常會要求IT管理單位能夠證明哪些用戶訪問了哪些數據，因記錄用戶行為有助於識別敏感數據上的可疑活動。

## Data Fabric 會收集哪些數據

* 使用 `maprcli` 、 `REST API` 與控制系統 `MCS` 執行的操作的所有管理員活動
* 控制系統`MCS`認證
* 目錄和文件的操作
* HPE Ezmeral Data Fabric Database 的操作
* HPE Ezmeral Data Fabric Event Store 的操作

## Data Fabric Auditing 的數據可以如何應用?

### 透過分析Audit紀錄，資料安全分析人員可以了解：

* 誰在工作時間之外訪問了客戶記錄？
* 用戶在離開公司前幾天採取了哪些行動？
* 在沒有遵循變更的SOP情況下執行了哪些操作？
* 用戶是否從受保護的IP地址訪問敏感文件？
* 為什麼來自相同基礎數據的報告看起來有所不同？

### 數據科學家可以分析審核記錄了解資料價值：

* 哪些數據最常使用，因此具有很高的價值，應該更廣泛地共享？
* 哪個數據最不常用，因此價值低，可以清除？
* 哪些數據應該更多地使用，因此未被充分利用並且需要更好的廣告發布？
* 哪些管理操作最常執行，因此是自動化的候選對象？

### 如何取用Auditing數據?

在`NFS Service` 、 `HDFS` 與 `CSI` 中都可以直接取用Log,路徑如下.

`<MapR Root>` / `<MapR Cluster Name>` /var/mapr/local/ `<Node Name> datafabric01.hpe-taiwan-cic.net` /audit/5560

```shell=
root@maprclient 5660]# ls
DBAudit.log-2021-02-03-001.json          TableMetricsAudit.log-2021-02-06-001.pb
DBAudit.log-2021-02-03-002.json          TableMetricsAudit.log-2021-02-07-001.pb
ExpandAudit.log-2021-02-03-001.json      Vollist_DBAudit.log-2021-02-03-001
ExpandAudit.log-2021-02-03-002.json      Vollist_DBAudit.log-2021-02-03-002
ExpandAudit.log-2021-02-06-001.json      Vollist_FSAudit.log-2021-02-03-001
ExpandAudit.log-2021-02-07-001.json      Vollist_FSAudit.log-2021-02-03-002
FSAudit.log-2021-02-03-001.json          Vollist_FSAudit.log-2021-02-06-001
FSAudit.log-2021-02-03-002.json          Vollist_FSAudit.log-2021-02-07-001
FSAudit.log-2021-02-06-001.json          Vollist_Metrics.log-2021-02-03-001
FSAudit.log-2021-02-07-001.json          Vollist_Metrics.log-2021-02-03-002
Metrics.log-2021-02-03-001.json          Vollist_TableMetricsAudit.log-2021-02-03-001
Metrics.log-2021-02-03-002.json          Vollist_TableMetricsAudit.log-2021-02-03-002
TableMetricsAudit.log-2021-02-03-001.pb  Vollist_TableMetricsAudit.log-2021-02-04-001
TableMetricsAudit.log-2021-02-03-002.pb  Vollist_TableMetricsAudit.log-2021-02-05-001
TableMetricsAudit.log-2021-02-04-001.pb  Vollist_TableMetricsAudit.log-2021-02-06-001
TableMetricsAudit.log-2021-02-05-001.pb  Vollist_TableMetricsAudit.log-2021-02-07-001
```

### Audit Log分為七大類

* DBAudit
* ExpandAudit
* FSAudit
* Metrics
* TableMetricsAudit
* Vollist_DBAudit
* Vollist_TableMetricsAudit

#### DBAudit Demo



