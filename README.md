# 技術筆記 Blog

🌐 **網站連結**: [https://hoycdanny.github.io](https://hoycdanny.github.io)

這是一個技術筆記集合，涵蓋 AI/ML、大數據、DevOps、IoT、網頁服務等主題。

## 📚 目錄結構

```
├── ai/                    # 人工智慧與機器學習
│   ├── h2o-driverless/   # H2O Driverless AI
│   └── mlops/            # MLOps 實踐
├── bigdata/              # 大數據技術
│   └── hadoop/           # Hadoop 生態系統
├── devops/               # DevOps 自動化
│   ├── ansible-ssh/      # Ansible 自動化
│   ├── jenkins/          # CI/CD
│   ├── oneview/          # HPE OneView
│   ├── pxe/              # PXE 網路啟動
│   ├── openstack/        # OpenStack 腳本
│   └── ku8install.sh     # Kubernetes 安裝
├── iot/                  # 物聯網與訊息佇列
│   ├── mqtt/             # EMQTT Kubernetes
│   ├── emqttd/           # EMQTT Docker
│   ├── mosquito-build/   # Mosquitto
│   ├── opendds/          # OpenDDS DDS
│   ├── lora/             # LoRa 長距離通訊
│   └── machan/           # MaChan 錯誤訊息
├── web/                  # 網頁伺服器
│   ├── nginx-reverse-proxy/
│   ├── nginx-reverse-proxy-tomcat-ssl/
│   └── websphere-liberty/
├── testing/              # 測試工具
│   └── tsung/            # 負載測試
├── container/            # 容器儲存
│   └── storage/nimble/   # HPE Nimble
├── hpe/                  # HPE 企業產品
│   └── ezmeral/          # Data Fabric
├── virtualization/       # 虛擬化
│   └── kvm/              # KVM
├── rhel/                 # Red Hat Linux
│   ├── upgrade/          # 系統升級
│   └── rhelrepo.md       # Repository 配置
└── programming/          # 程式語言
    └── go/              # Go 語言
```

## 🔖 快速導航

### 🤖 [AI & Machine Learning](ai/)
- [H2O Driverless AI](ai/h2o-driverless/) - 自動化機器學習平台
- [MLOps](ai/mlops/) - 機器學習運維
  - PyTorch 開發環境
  - TensorFlow 範例
  - Jupyter Notebook

### 📊 [大數據 (Big Data)](bigdata/)
- [Hadoop on CentOS](bigdata/hadoop/centos/) - Hadoop 叢集建置
- [Cloudera Quickstart](bigdata/hadoop/cloudera/) - Cloudera 快速部署

### 🔧 [DevOps 自動化](devops/)
- [Ansible SSH](devops/ansible-ssh/) - 自動化配置管理
- [Jenkins](devops/jenkins/) - CI/CD 伺服器
- [HPE OneView](devops/oneview/) - 伺服器自動化管理
- [PXE 網路啟動](devops/pxe/) - 網路啟動伺服器
- [OpenStack 腳本](devops/openstack/) - OpenStack 實例初始化腳本
- [Kubernetes 安裝](devops/ku8install.sh) - Kubernetes 安裝腳本

### 📡 [IoT 物聯網](iot/)
- [EMQTT Kubernetes](iot/mqtt/) - MQTT Broker 自動擴展
- [EMQTT Docker](iot/emqttd/) - MQTT Broker 容器
- [Mosquitto](iot/mosquito-build/) - 輕量級 MQTT
- [OpenDDS](iot/opendds/) - DDS 分散式通訊
- [LoRa](iot/lora/) - 長距離低功耗通訊
- [MaChan](iot/machan/) - MaChan 錯誤訊息定義

### 🌐 [Web 網頁伺服器](web/)
- [Nginx 反向代理](web/nginx-reverse-proxy/) - 負載平衡與反向代理
- [Nginx + Tomcat SSL](web/nginx-reverse-proxy-tomcat-ssl/) - HTTPS 配置
- [WebSphere Liberty](web/websphere-liberty/) - Java 應用伺服器

### 🧪 [Testing 測試工具](testing/)
- [Tsung](testing/tsung/) - 分散式負載測試工具

### 🐳 [Container 容器](container/)
- [HPE Nimble Storage](container/storage/nimble/) - Kubernetes 儲存整合
- [Docker 安裝範例](container/examples/) - CentOS Docker 安裝腳本

### 🏢 [HPE 產品](hpe/)
- [Ezmeral Data Fabric](hpe/ezmeral/data_fabric/) - 企業級資料平台

### 🖥️ [虛擬化 (Virtualization)](virtualization/)
- [CentOS KVM](virtualization/kvm/centos-kvm/) - KVM 虛擬化環境

### 🔧 [系統管理](rhel/)
- [RHEL 升級](rhel/upgrade/) - RHEL 7.9 to 8.2
- [RHEL Repository](rhel/rhelrepo.md) - 本地 Repository 配置

### � [程式語言](programming/)
- [Go 語言](programming/go/) - Go 開發環境

## 📊 技術棧

### AI/ML
- H2O Driverless AI, PyTorch, TensorFlow, MLOps

### 大數據
- Hadoop, HDFS, YARN, MapReduce, Cloudera, HPE Ezmeral Data Fabric

### DevOps
- Ansible, Jenkins, HPE OneView, Infrastructure as Code

### IoT & 訊息佇列
- MQTT (EMQTT, Mosquitto), DDS (OpenDDS), 即時通訊

### Web 服務
- Nginx, Tomcat, WebSphere Liberty, 反向代理, 負載平衡

### 測試
- Tsung, 負載測試, 壓力測試, 效能測試

### 容器 & 編排
- Docker, Kubernetes, CSI, HPE Nimble Storage

### 虛擬化
- KVM, QEMU, libvirt

### 作業系統
- CentOS, RHEL, Ubuntu

### 程式語言
- Go, Java, Python

## 🎯 使用場景

### 企業級應用
- 大數據處理與分析
- 自動化運維
- 高可用性部署
- 企業級儲存

### IoT 與即時系統
- MQTT 訊息代理
- DDS 即時通訊
- 設備管理
- 資料收集

### AI/ML 工作流程
- 模型訓練與部署
- 自動化機器學習
- MLOps 實踐
- 模型監控

### DevOps 實踐
- CI/CD 流程
- 基礎設施即程式碼
- 自動化測試
- 容器化部署

### Web 服務
- 反向代理
- 負載平衡
- SSL/TLS 終止
- 高效能網頁服務

## 🚀 特色

- ✅ **分類清晰**: 按技術領域組織，易於查找
- ✅ **實戰導向**: 來自實際專案的經驗分享
- ✅ **完整文件**: 詳細的安裝步驟和配置說明
- ✅ **範例豐富**: 提供大量 Dockerfile 和配置範例
- ✅ **持續更新**: 定期更新最新技術和最佳實踐

## 📖 如何使用

1. **瀏覽目錄**: 從上方目錄結構找到感興趣的主題
2. **點擊連結**: 進入具體的技術文件
3. **跟隨步驟**: 按照文件中的步驟進行操作
4. **參考範例**: 使用提供的配置文件和 Dockerfile

## 🤝 貢獻

歡迎提出問題和建議！

## 📝 授權

本專案採用開源授權，歡迎學習和參考。

---

*使用 Jekyll 主題: Hacker*
