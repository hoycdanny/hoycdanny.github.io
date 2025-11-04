# RHEL Repository Configuration

RHEL 本地 Repository 配置指南。

## 📋 設定步驟

### 1. 掛載 DVD

```bash
mount /dev/cdrom /mnt/tmp/
cd /mnt/tmp/
```

### 2. 複製檔案

```bash
mkdir /mnt/rheldvd
cp -r ./tmp/* rheldvd/
```

### 3. 配置 Repository

```bash
cp /mnt/tmp/media.repo /etc/yum.repos.d/rheldvd.repo
vim rheldvd.repo
```

新增以下內容：
```
baseurl=file:///mnt/rheldvd/
enabled=1
```

### 4. 設定權限並更新

```bash
chmod 644 /etc/yum.repos.d/rheldvd.repo
yum update
```

### 5. 安裝 EPEL Repository

```bash
yum install https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
yum update
```

## 🎯 使用場景

- 離線環境安裝套件
- 內部網路 Repository
- 版本控制管理
- 企業環境部署

---

*來源: MyGithub/cloud-deploy/rhelrepo.md*
