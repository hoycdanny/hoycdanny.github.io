# MLOps - Machine Learning Operations

機器學習運維相關的工具、實踐和範例。

## 📁 內容

### [Docker 環境](mlops/Dockerfile)
基於 NVIDIA PyTorch 的 MLOps 開發環境
- PyTorch 20.03
- OpenCV
- Jupyter Notebook (Port 8888)
- Flask (Port 8070, 5000)

### [TensorFlow 範例](tensorflow/)
- [Autoencoder 實作](tensorflow/tensorflow_autoencoder.ipynb) - TensorFlow 自編碼器範例

### [Demo](demo/)
MLOps 相關示範專案

## 🚀 快速開始

### 建置 Docker 映像

```bash
cd mlops
docker build -t mlops-env .
```

### 執行容器

```bash
docker run -it --gpus all \
  -p 8888:8888 \
  -p 8070:8070 \
  -p 5000:5000 \
  -v $(pwd):/workspace \
  mlops-env
```

### 啟動 Jupyter Notebook

```bash
jupyter notebook --ip=0.0.0.0 --port=8888 --allow-root
```

## 🔧 環境說明

### 已安裝套件
- **PyTorch**: 深度學習框架
- **OpenCV**: 電腦視覺函式庫
- **CMake**: 編譯工具
- **Vim**: 文字編輯器

### 開放端口
- `8888`: Jupyter Notebook
- `8070`: Flask 應用
- `5000`: Flask 預設端口
- `8080`: 保留端口
- `5901`: VNC (如有安裝)

## 📚 相關資源

- [NVIDIA NGC Catalog](https://catalog.ngc.nvidia.com/)
- [PyTorch 官方文件](https://pytorch.org/docs/)
- [TensorFlow 官方文件](https://www.tensorflow.org/)

## 🎯 MLOps 最佳實踐

1. **版本控制**: 程式碼、資料和模型版本管理
2. **自動化**: CI/CD 流程自動化
3. **監控**: 模型效能監控
4. **可重現性**: 確保實驗可重現
5. **協作**: 團隊協作與知識分享

---

*原始倉庫: [hoycdanny/mlops](https://github.com/hoycdanny/mlops)*
