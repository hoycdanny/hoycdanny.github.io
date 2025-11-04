# EMQTT Autoscale - MQTT Broker on Kubernetes

EMQ (Erlang MQTT Broker) 是一個分散式、高度可擴展的 MQTT 訊息代理，使用 Erlang/OTP 編寫。

本專案展示如何在 Kubernetes 上部署 EMQTT 並實現自動擴展。

## 📁 內容

- [k8s-emqttd/](k8s-emqttd/) - EMQTT 主節點 Kubernetes 配置
- [k8s-autoscalesvc/](k8s-autoscalesvc/) - EMQTT 自動擴展服務配置

## 🚀 快速開始

### 部署 EMQTT 到 Kubernetes

```bash
# 創建命名空間
kubectl create namespace emqtt

# 部署 EMQTT
kubectl apply -f k8s-emqttd/master.yaml
kubectl apply -f k8s-emqttd/mqtt.yaml

# 部署自動擴展服務
kubectl apply -f k8s-autoscalesvc/mqtt.yaml

# 查看服務狀態
kubectl get pods -n emqtt
kubectl get svc -n emqtt
```

### 訪問 EMQTT Dashboard

```bash
# 端口轉發
kubectl port-forward -n emqtt emqtt-0 8080:18083

# 瀏覽器訪問
http://localhost:8080
```

預設登入帳號：
- 用戶名：`admin`
- 密碼：`public`

## 🔧 配置說明

### 環境變數配置

EMQ 支援通過環境變數進行配置，前綴為 `EMQ_` 的環境變數會映射到配置文件。

#### 配置映射規則

```bash
EMQ_LISTENER__SSL__EXTERNAL__ACCEPTORS <--> listener.ssl.external.acceptors
EMQ_MQTT__MAX_PACKET_SIZE              <--> mqtt.max_packet_size
```

#### 常用配置

| 環境變數 | 預設值 | 說明 |
|---------|--------|------|
| EMQ_NAME | container name | EMQ 節點短名稱 |
| EMQ_HOST | container IP | EMQ 節點主機 |
| EMQ_JOIN_CLUSTER | none | 加入的叢集 |
| EMQ_ADMIN_PASSWORD | public | 管理員密碼 |
| EMQ_LISTENER__TCP__EXTERNAL | 1883 | MQTT TCP 端口 |
| EMQ_LISTENER__SSL__EXTERNAL | 8883 | MQTT TLS/SSL 端口 |
| EMQ_LISTENER__WS__EXTERNAL | 8083 | WebSocket 端口 |
| EMQ_LISTENER__WSS__EXTERNAL | 8084 | WSS 端口 |
| EMQ_LISTENER__API__MGMT | 8080 | 管理 API 端口 |
| EMQ_MQTT__ALLOW_ANONYMOUS | true | 允許匿名登入 |
| EMQ_MQTT__MAX_PACKET_SIZE | 64KB | 最大封包大小 |

### 插件配置

預設載入的插件：
- `emq_recon` - 性能監控
- `emq_modules` - 模組管理
- `emq_retainer` - 訊息保留
- `emq_dashboard` - Web 管理介面

載入額外插件：

```bash
EMQ_LOADED_PLUGINS="emq_auth_redis,emq_recon,emq_modules,emq_retainer,emq_dashboard"
```

## 🔌 端口說明

- `1883` - MQTT TCP
- `8883` - MQTT SSL/TLS
- `8083` - HTTP/WebSocket
- `8084` - HTTPS/WSS
- `8080` - 管理 API
- `18083` - Dashboard
- `4369` - Erlang 端口映射
- `6000-6999` - 叢集通訊端口

## 📊 叢集配置

### 建立叢集

```bash
docker run --rm -ti --name emq \
    -p 18083:18083 -p 1883:1883 -p 4369:4369 -p 6000-6100:6000-6100 \
    -e EMQ_NAME="emq" \
    -e EMQ_HOST="s2.emqtt.io" \
    -e EMQ_LISTENER__TCP__EXTERNAL=1883 \
    -e EMQ_JOIN_CLUSTER="emq@s1.emqtt.io" \
    emq:latest
```

### Kubernetes 叢集

在 Kubernetes 中，EMQTT 會自動發現並加入叢集。

## ⚙️ 系統調校

### Linux 核心參數

```bash
docker run --rm -ti --name emq \
    --sysctl fs.file-max=2097152 \
    --sysctl fs.nr_open=2097152 \
    --sysctl net.core.somaxconn=32768 \
    --sysctl net.ipv4.tcp_max_syn_backlog=16384 \
    --sysctl net.core.netdev_max_backlog=16384 \
    --sysctl net.ipv4.ip_local_port_range="1000 65535" \
    -p 18083:18083 -p 1883:1883 \
    emq:latest
```

## 📚 相關資源

- [EMQ 官方網站](https://www.emqx.io/)
- [EMQ 文件](https://docs.emqx.io/)
- [MQTT 協議](https://mqtt.org/)

## 🎯 使用場景

- IoT 設備通訊
- 即時訊息推送
- 車聯網
- 智慧家居
- 工業物聯網

---

*原始倉庫: [hoycdanny/emqtt-autoscale](https://github.com/hoycdanny/emqtt-autoscale)*
