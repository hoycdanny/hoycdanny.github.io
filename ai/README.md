# AI & Machine Learning 人工智慧與機器學習

人工智慧與機器學習相關技術筆記、平台部署和實踐。

## 📁 內容

### [H2O Driverless AI](h2o-driverless/)
H2O.ai 自動化機器學習平台的安裝與部署指南
- Docker 部署
- 自動化特徵工程
- 模型訓練與評估

### [MLOps](mlops/)
機器學習運維實踐、Docker 環境與範例
- PyTorch 開發環境
- TensorFlow Autoencoder 範例
- Jupyter Notebook 整合
- 模型部署與監控

## 🎯 主題涵蓋

### 機器學習平台
- **H2O Driverless AI**: 自動化機器學習
- **PyTorch**: 深度學習框架
- **TensorFlow**: 機器學習框架

### MLOps 實踐
- 模型訓練與部署
- CI/CD 流程
- 模型監控
- 版本控制
- 容器化部署

### 應用場景
- 自動化特徵工程
- 深度學習模型訓練
- 電腦視覺
- 自然語言處理
- 時間序列預測

## 🚀 快速開始

### H2O Driverless AI
```bash
# 下載並載入 Docker 映像
docker load < dai-docker-centos7-x86_64-1.7.0-10.0.tar.gz

# 執行容器
docker run --rm -p 12345:12345 -v $(pwd)/data:/data h2oai/dai-centos7-x86_64:1.7.0
```

### MLOps 環境
```bash
# 建置開發環境
cd mlops/mlops
docker build -t mlops-env .

# 啟動 Jupyter
docker run -it --gpus all -p 8888:8888 mlops-env
```

## 📚 學習資源

### 官方文件
- [H2O.ai 文件](https://docs.h2o.ai/)
- [PyTorch 教學](https://pytorch.org/tutorials/)
- [TensorFlow 指南](https://www.tensorflow.org/guide)

### 社群資源
- [Kaggle](https://www.kaggle.com/) - 資料科學競賽
- [Papers with Code](https://paperswithcode.com/) - 論文與程式碼
- [Hugging Face](https://huggingface.co/) - NLP 模型庫

## 🔧 工具與框架

### 深度學習框架
- PyTorch
- TensorFlow
- Keras

### AutoML 平台
- H2O Driverless AI
- AutoKeras
- Auto-sklearn

### MLOps 工具
- Docker
- Kubernetes
- MLflow
- Kubeflow

## 🎓 最佳實踐

1. **實驗追蹤**: 記錄所有實驗參數和結果
2. **版本控制**: 程式碼、資料和模型都要版本控制
3. **可重現性**: 確保實驗可以重現
4. **自動化**: 自動化訓練、測試和部署流程
5. **監控**: 持續監控模型效能
6. **文件化**: 詳細記錄模型和流程

---

*探索 AI/ML 的無限可能*
