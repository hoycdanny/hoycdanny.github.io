# HPE Ezmeral Data Fabric

HPE Ezmeral Data Fabric (前身為 MapR) 的技術筆記與操作指南。

## 📁 目錄結構

### [安裝 (Install)](install/)
Data Fabric 叢集的安裝與部署指南

### [管理 (Administrator)](administrator/)
- [Balancer](administrator/balancer/) - 資料平衡器設定
- [Cross-Cluster](administrator/cross-cluster/) - 跨叢集複製
- [User & Group](administrator/user-group/) - 使用者與群組管理

### [稽核 (Auditing)](auditing/)
系統稽核與日誌管理

### [開發 (Development)](development/)
- [CSI](development/csi/) - Container Storage Interface 整合
- [Database](development/db/) - MapR-DB 開發指南
- [VS Code Java Environment](development/vs-code-java-env/) - Java 開發環境設定

### [效能調校 (Performance)](performance/)
- [Apollo 4200 Gen9 4-Node](performance/apollo-4200-g9-4node/)
- [Apollo 4530 Gen9 3-Nodes](performance/apollo-4530-g9-3nodes/)

### [串流處理 (Stream)](stream/)
- [Why MapR Streams](stream/why/) - MapR Streams 介紹與優勢

## 核心元件

- **MapR-FS**: 分散式檔案系統
- **MapR-DB**: NoSQL 資料庫 (JSON & Binary)
- **MapR Streams**: 串流處理平台
- **CLDB**: Container Location Database
- **MFS**: MapR File System 服務

## 管理工具

- `maprcli`: 命令列管理工具
- MapR Control System (MCS): Web 管理介面
- REST API: 程式化管理介面

## 相關資源

- [官方文件](https://docs.datafabric.hpe.com/)
- [MapR Academy](https://learn.ezmeral.software.hpe.com/)
