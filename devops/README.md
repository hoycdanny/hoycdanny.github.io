# DevOps 自動化與運維

DevOps 工具、自動化部署和基礎設施管理相關技術。

## 📁 內容

### [Ansible SSH](ansible-ssh/)
Ansible 自動化管理容器
- SSH 遠端管理
- 自動化配置管理
- 批次操作

### [Jenkins](jenkins/)
持續整合/持續部署 (CI/CD) 伺服器
- 自動化建置
- 測試自動化
- 部署流程

### [HPE OneView](oneview/)
HPE DL380 伺服器自動化管理
- Ansible Playbook
- 伺服器配置管理
- 基礎設施即程式碼

## 🎯 DevOps 實踐

### 持續整合/持續部署 (CI/CD)
- 自動化建置流程
- 自動化測試
- 自動化部署
- 版本控制整合

### 基礎設施即程式碼 (IaC)
- Ansible 自動化
- 配置管理
- 環境一致性
- 可重現部署

### 自動化運維
- 批次管理
- 監控告警
- 日誌管理
- 故障自動恢復

## 🚀 快速開始

### Ansible 自動化

```bash
# 執行 Playbook
ansible-playbook -i hosts playbook.yml

# 檢查模式
ansible-playbook -i hosts playbook.yml --check

# 指定標籤
ansible-playbook -i hosts playbook.yml --tags "config"
```

### Jenkins CI/CD

```bash
# 啟動 Jenkins
docker run -d -p 8080:8080 jenkins:latest

# 查看初始密碼
docker exec <container-id> cat /var/lib/jenkins/secrets/initialAdminPassword
```

## 📚 相關資源

- [Ansible 文件](https://docs.ansible.com/)
- [Jenkins 文件](https://www.jenkins.io/doc/)
- [HPE OneView API](https://hewlettpackard.github.io/oneview-python/)

---

*自動化讓運維更高效*
