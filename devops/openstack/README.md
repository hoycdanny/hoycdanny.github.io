# OpenStack Instance Shell Scripts

OpenStack 虛擬機實例初始化腳本集合。

## 📋 說明

這些腳本用於在 OpenStack 虛擬機啟動時自動安裝和配置各種服務。

## 📁 腳本列表

### [apache2.sh](InstanceShell/apache2.sh)
Apache HTTP 伺服器安裝腳本

### [docker.sh](InstanceShell/docker.sh)
Docker 容器引擎安裝腳本

### [haproxy.sh](InstanceShell/haproxy.sh)
HAProxy 負載平衡器安裝腳本

### [kubernetes.sh](InstanceShell/kubernetes.sh)
Kubernetes 容器編排平台安裝腳本

### [openshift.sh](InstanceShell/openshift.sh)
OpenShift 容器平台安裝腳本

### [tsung.sh](InstanceShell/tsung.sh)
Tsung 負載測試工具安裝腳本（二進位版本）

### [tsung-source.sh](InstanceShell/tsung-source.sh)
Tsung 負載測試工具安裝腳本（原始碼編譯版本）

## 🚀 使用方式

### 在 OpenStack 中使用

1. 建立虛擬機時，在 "Configuration" 或 "Post-Creation" 標籤中
2. 將腳本內容貼到 "Customization Script" 或 "User Data" 欄位
3. 啟動虛擬機，腳本會自動執行

### 手動執行

```bash
chmod +x InstanceShell/docker.sh
sudo ./InstanceShell/docker.sh
```

## 🎯 使用場景

- **快速部署**: 自動化服務安裝
- **標準化環境**: 確保配置一致性
- **雲端自動化**: 與 OpenStack Heat 整合
- **測試環境**: 快速建立測試實例

## 📝 注意事項

- 這些腳本設計用於 CentOS/RHEL 系統
- 需要 root 權限執行
- 建議在測試環境先驗證
- 可根據需求修改腳本內容

---

*來源: MyGithub/cloud-deploy/Cloud/OpenStack*
