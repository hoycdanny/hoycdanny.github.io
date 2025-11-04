# Docker OpenDDS

OpenDDS 是一個開源的 C++ 實作，遵循 Object Management Group (OMG) 的 Data Distribution Service (DDS) 規範。

## 📦 關於 OpenDDS

OpenDDS 提供了一個高效能、可擴展的發布-訂閱通訊框架，適用於分散式系統。

### 主要特性

- 符合 OMG DDS 規範
- 支援多種傳輸協議（TCP, UDP, 多播）
- 跨平台支援
- 高效能、低延遲
- 可靠的資料傳輸

## 🚀 使用方式

### 建置 Docker 映像

```bash
docker build -t opendds:3.10 .
```

### 執行容器

```bash
docker run -it --rm opendds:3.10 /bin/bash
```

### 在容器中使用 OpenDDS

```bash
# 環境變數已設定
echo $DDS_ROOT
echo $ACE_ROOT
echo $TAO_ROOT

# 執行範例
cd $DDS_ROOT/DevGuideExamples/DCPS/Messenger
./run_test.pl
```

## 🔧 環境變數

容器中已設定以下環境變數：

- `DDS_ROOT=/OpenDDS-3.10`
- `ACE_ROOT=/OpenDDS-3.10/ACE_wrappers`
- `TAO_ROOT=/OpenDDS-3.10/ACE_wrappers`

## 📚 已安裝套件

- OpenDDS 3.10
- ACE/TAO
- Xerces-C (XML 解析器)
- Qt4 開發工具
- Boost 函式庫
- GLib 開發函式庫

## 🎯 使用場景

- 分散式系統通訊
- 即時資料分發
- 工業自動化
- 國防系統
- 金融交易系統
- 物聯網資料交換

## 📖 相關資源

- [OpenDDS 官方網站](https://opendds.org/)
- [OpenDDS GitHub](https://github.com/objectcomputing/OpenDDS)
- [DDS 規範](https://www.omg.org/spec/DDS/)
- [OpenDDS 開發者指南](https://opendds.readthedocs.io/)

## 🔗 相關技術

- **DDS**: Data Distribution Service
- **ACE**: ADAPTIVE Communication Environment
- **TAO**: The ACE ORB (CORBA 實作)
- **RTPS**: Real-Time Publish-Subscribe Protocol

---

*原始倉庫: [hoycdanny/docker-opendds](https://github.com/hoycdanny/docker-opendds)*
