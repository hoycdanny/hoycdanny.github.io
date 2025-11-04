# Container 容器技術

容器化技術、Docker、Kubernetes 相關工具與實踐。

## 📁 內容分類

### 🐳 Dockerfile 範例集合
**[dockerfiles/](dockerfiles/)** - 各種應用的 Dockerfile 範例

#### 自動化與 CI/CD
- [ansible-ssh](dockerfiles/ansible-ssh/) - Ansible SSH 管理容器
- [jenkins](dockerfiles/jenkins/) - Jenkins CI/CD 伺服器

#### 訊息佇列與通訊
- [emqttd](dockerfiles/emqttd/) - EMQ MQTT Broker
- [mosquito-build](dockerfiles/mosquito-build/) - Mosquitto MQTT Broker
- [opendds](dockerfiles/opendds/) - OpenDDS 分散式通訊

#### 網頁伺服器與反向代理
- [nginx-reverse-proxy](dockerfiles/nginx-reverse-proxy/) - Nginx 反向代理
- [nginx-reverse-proxy-tomcat-ssl](dockerfiles/nginx-reverse-proxy-tomcat-ssl/) - Nginx + Tomcat SSL
- [websphere-liberty](dockerfiles/websphere-liberty/) - IBM WebSphere Liberty

#### 測試與開發工具
- [tsung](dockerfiles/tsung/) - Tsung 負載測試工具
- [faas-netes](dockerfiles/faas-netes/) - FaaS on Kubernetes
- [demo-tutum](dockerfiles/demo-tutum/) - Tutum 示範專案

### 📡 MQTT 訊息佇列
**[mqtt/](mqtt/)** - EMQTT Kubernetes 自動擴展
- EMQ MQTT Broker 部署
- Kubernetes 自動擴展配置
- 叢集配置與管理

### 🔄 分散式通訊
**[opendds/](opendds/)** - OpenDDS Docker 容器
- DDS (Data Distribution Service) 實作
- 即時系統通訊
- 發布-訂閱模式

### 💾 儲存方案
**[storage/nimble/](storage/nimble/)** - HPE Nimble Storage 整合
- Docker Volume Plugin
- Kubernetes CSI Driver
- 持久化儲存管理

## 🎯 使用場景

### 微服務架構
- 服務容器化
- 服務發現
- 負載平衡
- API Gateway

### DevOps 實踐
- CI/CD 流程
- 自動化部署
- 環境一致性
- 快速回滾

### IoT 與即時通訊
- MQTT 訊息代理
- DDS 即時通訊
- 設備管理
- 資料收集

### 企業應用
- 應用伺服器容器化
- 資料庫容器化
- 持久化儲存
- 高可用性部署

## 🚀 快速開始

### Docker 基礎

```bash
# 建置映像
docker build -t myapp:latest .

# 執行容器
docker run -d -p 8080:8080 myapp:latest

# 查看容器
docker ps

# 查看日誌
docker logs <container-id>
```

### Kubernetes 部署

```bash
# 部署應用
kubectl apply -f deployment.yaml

# 查看 Pod
kubectl get pods

# 查看服務
kubectl get svc

# 查看日誌
kubectl logs <pod-name>
```

### Docker Compose

```bash
# 啟動服務
docker-compose up -d

# 查看狀態
docker-compose ps

# 停止服務
docker-compose down
```

## 🔧 核心技術

### 容器技術
- **Docker**: 容器引擎
- **containerd**: 容器運行時
- **runc**: OCI 運行時

### 編排工具
- **Kubernetes**: 容器編排平台
- **Docker Swarm**: Docker 原生編排
- **Nomad**: HashiCorp 編排工具

### 網路
- **CNI**: 容器網路介面
- **Calico**: 網路與安全
- **Flannel**: 覆蓋網路

### 儲存
- **CSI**: 容器儲存介面
- **Volume Plugins**: Docker 儲存插件
- **Persistent Volumes**: Kubernetes 持久化儲存

## 📚 相關資源

### 官方文件
- [Docker 文件](https://docs.docker.com/)
- [Kubernetes 文件](https://kubernetes.io/docs/)
- [CNCF 專案](https://www.cncf.io/projects/)

### 學習資源
- [Docker Hub](https://hub.docker.com/)
- [Kubernetes Academy](https://kubernetes.academy/)
- [Play with Docker](https://labs.play-with-docker.com/)

### 最佳實踐
- [12-Factor App](https://12factor.net/)
- [Container Best Practices](https://cloud.google.com/architecture/best-practices-for-building-containers)

## 🛡️ 安全建議

1. **映像安全**
   - 使用官方基礎映像
   - 定期更新映像
   - 掃描漏洞

2. **運行時安全**
   - 非 root 用戶執行
   - 限制資源使用
   - 網路隔離

3. **密鑰管理**
   - 使用 Secrets 管理
   - 不在映像中存放密鑰
   - 定期輪換密鑰

---

*容器化讓部署更簡單、更可靠*
