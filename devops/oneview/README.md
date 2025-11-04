# HPE OneView Ansible Demo for DL380

使用 Ansible 自動化管理 HPE DL380 伺服器的示範專案，透過 HPE OneView API 進行基礎設施即程式碼 (Infrastructure as Code) 的實踐。

## 📋 專案說明

本專案展示如何使用 Ansible 和 HPE OneView 自動化配置和管理 HPE ProLiant DL380 伺服器。

## 📁 檔案說明

- `hosts` - Ansible inventory 檔案
- `oneview-config.json` - HPE OneView 連線配置
- `infrastructure-config.yml` - 基礎設施配置參數
- `run.yml` - 主要的 Ansible playbook

## 🚀 快速開始

### 前置需求

1. **安裝 Ansible**

```bash
# Ubuntu/Debian
sudo apt-get install ansible

# CentOS/RHEL
sudo yum install ansible

# macOS
brew install ansible
```

2. **安裝 HPE OneView SDK for Python**

```bash
pip install hpOneView
```

3. **安裝 Ansible HPE OneView 模組**

```bash
ansible-galaxy collection install hpe.oneview
```

### 配置

1. **編輯 OneView 連線配置**

編輯 `oneview-config.json`：

```json
{
  "ip": "your-oneview-ip",
  "credentials": {
    "userName": "administrator",
    "password": "your-password"
  },
  "api_version": 1200
}
```

2. **編輯基礎設施配置**

編輯 `infrastructure-config.yml` 設定伺服器參數。

3. **編輯 Inventory**

編輯 `hosts` 檔案，設定目標主機。

### 執行

```bash
# 執行 playbook
ansible-playbook -i hosts run.yml

# 檢查模式（不實際執行）
ansible-playbook -i hosts run.yml --check

# 詳細輸出
ansible-playbook -i hosts run.yml -vvv
```

## 🔧 功能特性

### 自動化任務

- 伺服器配置管理
- 網路設定
- 儲存配置
- 韌體更新
- 電源管理
- 監控和告警

### HPE OneView 整合

- Server Profile 管理
- Server Hardware 管理
- Network 配置
- Storage Volume 管理
- Enclosure 管理

## 📖 HPE OneView 概念

### Server Profile
定義伺服器的完整配置，包括：
- BIOS 設定
- 網路連線
- 儲存配置
- 開機順序

### Server Profile Template
可重複使用的伺服器配置範本。

### Server Hardware
實體伺服器硬體資源。

### Enclosure
刀鋒伺服器機箱。

## 🎯 使用場景

- **資料中心自動化**：大規模伺服器部署
- **基礎設施即程式碼**：版本控制的基礎設施配置
- **災難復原**：快速重建伺服器配置
- **標準化部署**：確保配置一致性
- **DevOps 整合**：CI/CD 流程整合

## 📚 相關資源

- [HPE OneView 官方文件](https://www.hpe.com/us/en/integrated-systems/software.html)
- [HPE OneView Python SDK](https://github.com/HewlettPackard/oneview-python)
- [Ansible HPE OneView Collection](https://galaxy.ansible.com/hpe/oneview)
- [HPE OneView API 文件](https://hewlettpackard.github.io/oneview-python/)

## 🔐 安全建議

1. **不要提交敏感資訊**
   - 使用 Ansible Vault 加密密碼
   - 將 `oneview-config.json` 加入 `.gitignore`

2. **使用 Ansible Vault**

```bash
# 加密檔案
ansible-vault encrypt oneview-config.json

# 執行時解密
ansible-playbook -i hosts run.yml --ask-vault-pass
```

3. **最小權限原則**
   - 使用專用的 OneView 帳號
   - 僅授予必要的權限

## 🛠️ 故障排除

### 常見問題

1. **連線失敗**
   - 檢查 OneView IP 和憑證
   - 確認網路連通性
   - 驗證 API 版本

2. **認證錯誤**
   - 確認用戶名和密碼
   - 檢查帳號權限

3. **模組找不到**
   - 確認已安裝 HPE OneView collection
   - 檢查 Ansible 版本

## 📝 最佳實踐

1. **使用版本控制**：將配置檔案納入 Git 管理
2. **模組化設計**：將 playbook 拆分為可重用的 roles
3. **測試環境**：先在測試環境驗證
4. **文件化**：記錄配置變更和決策
5. **監控和日誌**：保留執行日誌以供審計

## 🔄 持續改進

- 增加更多自動化任務
- 整合監控系統
- 實作自動化測試
- 建立配置範本庫

---

*原始倉庫: [hoycdanny/oneview-ansible-demo-for-dl380](https://github.com/hoycdanny/oneview-ansible-demo-for-dl380)*
