# Testing 測試工具

效能測試、負載測試和壓力測試相關工具。

## 📁 內容

### [Tsung](tsung/)
分散式多協議負載測試工具
- HTTP/HTTPS 測試
- WebSocket 測試
- MQTT 測試
- PostgreSQL/MySQL 測試
- 分散式測試
- 即時報表

## 🎯 測試類型

### 負載測試 (Load Testing)
測試系統在預期負載下的表現
- 模擬正常使用情境
- 驗證系統容量
- 找出效能瓶頸

### 壓力測試 (Stress Testing)
測試系統在極限負載下的表現
- 超出正常負載
- 找出系統極限
- 測試錯誤處理

### 耐久測試 (Endurance Testing)
測試系統長時間運行的穩定性
- 長時間持續負載
- 記憶體洩漏檢測
- 資源消耗分析

## 🚀 Tsung 使用

### 基本配置

```xml
<?xml version="1.0"?>
<!DOCTYPE tsung SYSTEM "/usr/share/tsung/tsung-1.0.dtd">
<tsung loglevel="notice" version="1.0">
  <clients>
    <client host="localhost" use_controller_vm="true"/>
  </clients>

  <servers>
    <server host="your-server.com" port="80" type="tcp"/>
  </servers>

  <load>
    <arrivalphase phase="1" duration="1" unit="minute">
      <users maxnumber="100" arrivalrate="10" unit="second"/>
    </arrivalphase>
  </load>

  <sessions>
    <session name="http-example" probability="100" type="ts_http">
      <request>
        <http url='/' method='GET' version='1.1'/>
      </request>
    </session>
  </sessions>
</tsung>
```

### 執行測試

```bash
# 啟動測試
tsung -f config.xml start

# 查看即時狀態
tsung status

# 停止測試
tsung stop

# 生成報表
cd ~/.tsung/log/<timestamp>/
/usr/lib/tsung/bin/tsung_stats.pl
```

### Docker 部署

```bash
# 建置映像
docker build -t tsung:latest tsung/

# 執行測試
docker run -v $(pwd)/config.xml:/usr/local/tsung/config.xml tsung:latest
```

## 📊 測試指標

### 效能指標
- **回應時間**: 請求到回應的時間
- **吞吐量**: 單位時間處理的請求數
- **並發用戶數**: 同時在線用戶數
- **錯誤率**: 失敗請求的比例

### 系統指標
- **CPU 使用率**: 處理器負載
- **記憶體使用**: 記憶體消耗
- **網路頻寬**: 網路流量
- **磁碟 I/O**: 讀寫速度

## 🔧 支援協議

### HTTP/HTTPS
- GET, POST, PUT, DELETE
- Cookie 管理
- Session 管理
- 動態內容

### WebSocket
- 雙向通訊
- 即時訊息
- 長連接

### MQTT
- 發布/訂閱
- QoS 測試
- 連接測試

### 資料庫
- PostgreSQL
- MySQL
- 查詢效能測試

## 📈 最佳實踐

### 測試規劃
1. 定義測試目標
2. 設計測試場景
3. 準備測試資料
4. 設定監控

### 測試執行
1. 從小負載開始
2. 逐步增加負載
3. 監控系統指標
4. 記錄異常情況

### 結果分析
1. 分析效能指標
2. 找出瓶頸
3. 提出優化建議
4. 驗證優化效果

## 📚 相關資源

- [Tsung 官方網站](http://tsung.erlang-projects.org/)
- [Tsung 文件](http://tsung.erlang-projects.org/user_manual/)
- [效能測試最佳實踐](https://www.guru99.com/performance-testing.html)

---

*測試保證品質*
