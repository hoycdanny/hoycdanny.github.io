# Web 網頁伺服器

網頁伺服器、反向代理和應用伺服器相關技術。

## 📁 內容

### [Nginx 反向代理](nginx-reverse-proxy/)
Nginx 反向代理伺服器
- 負載平衡
- SSL/TLS 終止
- 靜態內容服務
- 反向代理配置

### [Nginx + Tomcat SSL](nginx-reverse-proxy-tomcat-ssl/)
Nginx 反向代理 Tomcat 並啟用 SSL
- HTTPS 配置
- Tomcat 整合
- SSL 憑證管理
- 安全加固

### [WebSphere Liberty](websphere-liberty/)
IBM WebSphere Liberty 應用伺服器
- Java EE 應用
- 輕量級伺服器
- 微服務架構
- 容器化部署

## 🎯 使用場景

### 反向代理
- 負載平衡
- SSL 終止
- 快取加速
- 安全防護

### 應用伺服器
- Java Web 應用
- 企業級應用
- 微服務部署
- API Gateway

### 靜態內容服務
- HTML/CSS/JS
- 圖片/影片
- 檔案下載
- CDN 整合

## 🚀 快速開始

### Nginx 反向代理

```bash
# 建置映像
docker build -t nginx-proxy:latest nginx-reverse-proxy/

# 執行容器
docker run -d -p 80:80 -p 443:443 nginx-proxy:latest
```

### Nginx 配置範例

```nginx
upstream backend {
    server backend1:8080;
    server backend2:8080;
    server backend3:8080;
}

server {
    listen 80;
    server_name example.com;

    location / {
        proxy_pass http://backend;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
    }
}
```

### SSL 配置

```nginx
server {
    listen 443 ssl http2;
    server_name example.com;

    ssl_certificate /etc/nginx/ssl/cert.pem;
    ssl_certificate_key /etc/nginx/ssl/key.pem;
    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_ciphers HIGH:!aNULL:!MD5;

    location / {
        proxy_pass http://backend;
    }
}
```

### WebSphere Liberty

```bash
# 建置映像
docker build -t liberty:latest websphere-liberty/

# 執行容器
docker run -d -p 9080:9080 -p 9443:9443 liberty:latest
```

## 🔧 核心功能

### Nginx 特性
- **高效能**: 事件驅動架構
- **低資源消耗**: 記憶體使用少
- **高並發**: 支援大量連接
- **模組化**: 豐富的模組生態

### 負載平衡演算法
- **Round Robin**: 輪詢
- **Least Connections**: 最少連接
- **IP Hash**: IP 雜湊
- **Weighted**: 加權分配

### SSL/TLS
- HTTPS 加密
- 憑證管理
- 協議版本控制
- 加密套件配置

## 📊 效能優化

### Nginx 優化
```nginx
# Worker 進程數
worker_processes auto;

# 連接數限制
worker_connections 1024;

# 啟用 Gzip 壓縮
gzip on;
gzip_types text/plain text/css application/json;

# 快取配置
proxy_cache_path /var/cache/nginx levels=1:2 keys_zone=my_cache:10m;
```

### 快取策略
- 瀏覽器快取
- 代理快取
- CDN 快取
- 應用快取

## 🛡️ 安全建議

### Nginx 安全
1. 隱藏版本資訊
2. 限制請求大小
3. 防止 DDoS
4. 設定速率限制
5. 啟用 HTTPS

### SSL 最佳實踐
1. 使用強加密套件
2. 啟用 HSTS
3. 定期更新憑證
4. 禁用舊協議
5. 實施 OCSP Stapling

## 📚 相關資源

- [Nginx 官方文件](https://nginx.org/en/docs/)
- [Nginx 配置範例](https://www.nginx.com/resources/wiki/start/)
- [WebSphere Liberty 文件](https://www.ibm.com/docs/en/was-liberty)
- [SSL Labs 測試](https://www.ssllabs.com/ssltest/)

---

*高效能網頁服務*
