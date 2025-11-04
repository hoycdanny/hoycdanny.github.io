# Hadoop

Apache Hadoop 是一個開源的分散式儲存和處理框架。

## 安裝指南

- [CentOS 環境](centos/) - 在 CentOS/Ubuntu 上手動安裝 Hadoop 叢集
- [Cloudera 快速啟動](cloudera/) - 使用 Docker 部署 Cloudera Hadoop 環境

## 核心元件

- **HDFS**: 分散式檔案系統
- **YARN**: 資源管理器
- **MapReduce**: 分散式計算框架

## 架構說明

- **NameNode**: HDFS 的主節點，管理檔案系統的命名空間
- **DataNode**: HDFS 的工作節點，儲存實際資料
- **ResourceManager**: YARN 的主節點，管理叢集資源
- **NodeManager**: YARN 的工作節點，管理單一節點的資源
