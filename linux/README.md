# Linux 系統管理

Linux 系統管理、DNS 管理和控制面板相關工具。

## 📁 內容

### [Atomia](Atomia/)
Atomia DNS 管理系統 Docker 容器
- DNS 管理平台
- 自動化 DNS 配置
- 多租戶支援

### [ISPConfig](ISPconfig/)
ISPConfig 控制面板安裝腳本
- Web 主機控制面板
- 郵件伺服器管理
- DNS 管理
- FTP 管理

### [DNS Manager](DNS-Manager.sh)
DNS 管理腳本
- 自動化 DNS 配置
- 批次管理
- 快速部署

## 🎯 使用場景

### DNS 管理
- 域名解析管理
- DNS 記錄批次操作
- 自動化 DNS 配置
- 多域名管理

### Web 主機管理
- 虛擬主機管理
- 郵件伺服器
- FTP 伺服器
- 資料庫管理

### 系統自動化
- 批次部署
- 配置管理
- 監控告警
- 備份還原

## 🚀 快速開始

### Atomia DNS

```bash
# 建置容器
cd Atomia
docker build -t atomia-dns:latest .

# 執行容器
docker run -d -p 53:53/udp -p 53:53/tcp atomia-dns:latest
```

### ISPConfig 安裝

```bash
# 執行安裝腳本
cd ISPconfig
chmod +x install.sh
sudo ./install.sh
```

### DNS Manager

```bash
# 執行 DNS 管理腳本
chmod +x DNS-Manager.sh
sudo ./DNS-Manager.sh
```

## 📚 相關資源

- [Atomia 官方網站](https://atomia.com/)
- [ISPConfig 文件](https://www.ispconfig.org/documentation/)
- [BIND DNS 文件](https://www.isc.org/bind/)

---

*簡化 Linux 系統管理*
