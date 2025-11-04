# IoT 物聯網與訊息佇列

物聯網 (IoT) 相關的訊息佇列、通訊協議和分散式系統。

## 📁 內容

### [EMQTT](mqtt/)
EMQ MQTT Broker Kubernetes 自動擴展
- MQTT 訊息代理
- Kubernetes 部署
- 自動擴展配置
- 叢集管理

### [EMQTT Docker](emqttd/)
EMQ MQTT Broker Docker 容器
- Docker 部署
- 環境變數配置
- 插件管理

### [Mosquitto](mosquito-build/)
Mosquitto MQTT Broker 建置環境
- 輕量級 MQTT Broker
- 開源實作
- 簡單部署

### [OpenDDS](opendds/)
DDS (Data Distribution Service) 分散式通訊
- 即時資料分發
- 發布-訂閱模式
- 高效能通訊

## 🎯 使用場景

### IoT 設備通訊
- 感測器資料收集
- 設備控制
- 即時監控
- 資料聚合

### 訊息佇列
- 非同步通訊
- 訊息緩衝
- 負載平衡
- 解耦服務

### 即時系統
- 工業自動化
- 車聯網
- 智慧家居
- 即時監控

## 📡 MQTT 協議

### 特性
- 輕量級協議
- 發布/訂閱模式
- QoS 服務品質
- 保留訊息
- 遺囑訊息

### QoS 等級
- **QoS 0**: 最多一次 (At most once)
- **QoS 1**: 至少一次 (At least once)
- **QoS 2**: 恰好一次 (Exactly once)

## 🚀 快速開始

### EMQTT 部署

```bash
# Kubernetes 部署
kubectl create namespace emqtt
kubectl apply -f mqtt/k8s-emqttd/

# 訪問 Dashboard
kubectl port-forward -n emqtt emqtt-0 18083:18083
```

### Mosquitto 使用

```bash
# 啟動 Broker
mosquitto -c mosquitto.conf

# 訂閱主題
mosquitto_sub -h localhost -t "test/topic"

# 發布訊息
mosquitto_pub -h localhost -t "test/topic" -m "Hello MQTT"
```

### OpenDDS 範例

```bash
# 建置容器
docker build -t opendds:latest opendds/

# 執行範例
docker run -it opendds:latest
cd $DDS_ROOT/DevGuideExamples/DCPS/Messenger
./run_test.pl
```

## 🔧 核心技術

### MQTT Brokers
- **EMQTT**: 企業級 MQTT Broker
- **Mosquitto**: 輕量級開源 Broker
- **HiveMQ**: 商業級 MQTT 平台

### DDS 實作
- **OpenDDS**: 開源 C++ 實作
- **RTI Connext**: 商業級 DDS
- **Fast DDS**: 高效能實作

## 📚 相關資源

- [MQTT 官方網站](https://mqtt.org/)
- [EMQX 文件](https://www.emqx.io/docs/)
- [Mosquitto 文件](https://mosquitto.org/documentation/)
- [OpenDDS 文件](https://opendds.org/)
- [DDS 規範](https://www.omg.org/spec/DDS/)

---

*連接萬物，即時通訊*
