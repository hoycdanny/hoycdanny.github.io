# Go 語言開發環境設定

## 安裝 Go

下載並安裝 Go 語言：

```bash
wget https://dl.google.com/go/go1.12.6.linux-amd64.tar.gz
tar -xzf go1.12.6.linux-amd64.tar.gz
sudo mv go /usr/local
```

## 設定環境變數

編輯 `~/.bashrc` 或 `~/.bash_profile`：

```bash
export GOROOT=/usr/local/go
export GOPATH=$HOME/go
export PATH=$GOPATH/bin:$GOROOT/bin:$PATH
```

套用設定：

```bash
source ~/.bashrc
```

## 驗證安裝

```bash
go version
go env
```

## 範例：編譯 OpenShift Installer

```bash
git clone https://github.com/openshift/installer.git
cd installer/
hack/build.sh
```

## 常用指令

- `go version` - 查看 Go 版本
- `go env` - 查看 Go 環境變數
- `go build` - 編譯程式
- `go run` - 執行程式
- `go get` - 下載並安裝套件
- `go mod init` - 初始化模組
- `go mod tidy` - 整理依賴套件

## 相關資源

- [Go 官方文件](https://golang.org/doc/)
- [Go by Example](https://gobyexample.com/)
- [Effective Go](https://golang.org/doc/effective_go.html)

