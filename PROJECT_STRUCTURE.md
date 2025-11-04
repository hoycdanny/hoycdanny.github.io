# 專案結構說明

這是一個使用 Jekyll 建置的技術筆記 Blog，託管於 GitHub Pages。

## 📂 目錄結構

```
.
├── _config.yml                    # Jekyll 配置文件
├── .gitignore                     # Git 忽略文件
├── index.md                       # 首頁
├── README.md                      # 專案說明（GitHub 顯示用）
│
├── ai/                            # AI & 機器學習
│   ├── README.md
│   └── h2o-driverless/
│       └── README.md              # H2O Driverless AI 安裝指南
│
├── bigdata/                       # 大數據技術
│   ├── README.md
│   └── hadoop/
│       ├── README.md
│       ├── centos/
│       │   └── README.md          # Hadoop on CentOS 安裝
│       └── cloudera/
│           └── README.md          # Cloudera 快速啟動
│
├── container/                     # 容器技術
│   ├── README.md
│   └── storage/
│       ├── README.md
│       └── nimble/
│           ├── README.md          # Nimble Storage 整合指南
│           └── images/            # 相關圖片
│
├── hpe/                           # HPE 產品
│   ├── README.md
│   └── ezmeral/
│       ├── README.md
│       └── data_fabric/
│           ├── README.md
│           ├── administrator/     # 管理相關
│           │   ├── balancer/
│           │   ├── cross-cluster/
│           │   └── user-group/
│           ├── auditing/          # 稽核
│           ├── development/       # 開發
│           │   ├── csi/
│           │   ├── db/
│           │   └── vs-code-java-env/
│           ├── install/           # 安裝
│           │   └── 6.2/
│           ├── performance/       # 效能調校
│           │   ├── apollo-4200-g9-4node/
│           │   └── apollo-4530-g9-3nodes/
│           └── stream/            # 串流處理
│               └── why/
│
├── programming/                   # 程式語言
│   ├── README.md
│   └── go/
│       └── README.md              # Go 開發環境設定
│
├── rhel/                          # Red Hat Enterprise Linux
│   ├── README.md
│   └── upgrade/
│       └── README.md              # RHEL 7.9 to 8.2 升級指南
│
└── virtualization/                # 虛擬化技術
    ├── README.md
    └── kvm/
        ├── README.md
        └── centos-kvm/
            └── README.md          # CentOS KVM 安裝
```

## 📝 內容組織原則

1. **階層式結構**: 每個主題都有自己的目錄，並包含 README.md 作為索引
2. **清晰的命名**: 使用英文小寫和連字號，避免空格
3. **完整的導航**: 每個 README.md 都包含上下文連結
4. **中英對照**: 標題使用中英文對照，方便理解

## 🔧 維護指南

### 新增文章

1. 在適當的分類目錄下創建新的資料夾
2. 在資料夾中創建 README.md
3. 更新上層目錄的 README.md，加入新文章的連結

### 新增分類

1. 在根目錄創建新的分類資料夾
2. 創建該分類的 README.md
3. 更新根目錄的 README.md 和 index.md

### 圖片管理

- 圖片放在文章所在目錄的 `images/` 子目錄
- 使用相對路徑引用圖片
- 圖片命名要有意義

## 🚀 本地預覽

```bash
# 安裝 Jekyll
gem install jekyll bundler

# 啟動本地伺服器
jekyll serve

# 瀏覽器開啟
http://localhost:4000
```

## 📦 部署

推送到 GitHub 後，GitHub Pages 會自動建置並部署網站。

## 🎨 主題

使用 Jekyll 官方主題 `jekyll-theme-hacker`，適合技術文件展示。

## 📄 授權

請根據需求添加適當的授權條款。
