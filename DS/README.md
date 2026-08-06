<div align="center">

# 📊 Introduction to Data Science Lab

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=22&duration=3000&pause=800&color=00B4D8&center=true&vCenter=true&width=650&lines=Import+%E2%86%92+Clean+%E2%86%92+Explore+%E2%86%92+Model+%E2%86%92+Evaluate;40+experiments%2C+one+pipeline%2C+start+to+finish;Pandas+%C2%B7+NumPy+%C2%B7+SciPy+%C2%B7+Scikit-learn+%C2%B7+Seaborn" alt="Typing SVG" />

![Language](https://img.shields.io/badge/Python-3.14-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Subject](https://img.shields.io/badge/CSE022D715-Data%20Science%20Lab-00B4D8?style=for-the-badge)
![Semester](https://img.shields.io/badge/B.Tech-5th%20Sem-success?style=for-the-badge)
![Dept](https://img.shields.io/badge/Dept.%20of%20CSE-RSET-maroon?style=for-the-badge)

![Experiments](https://img.shields.io/badge/Experiments-40-blueviolet?style=flat-square)
![Status](https://img.shields.io/badge/Progress-1%20%2F%2040-orange?style=flat-square)
![Datasets](https://img.shields.io/badge/External%20datasets-not%20required-brightgreen?style=flat-square)

</div>

---

> **The whole lab is one story.** You pull data in, you clean it, you look at it, you fit a
> model to it, and then you find out whether the model was any good. Experiments 1–40 walk
> that path in order — nothing here is a detour.

```
  ┌─────────┐   ┌──────────┐   ┌─────────┐   ┌────────┐   ┌──────────┐
  │ IMPORT  │──▶│  CLEAN   │──▶│ EXPLORE │──▶│ MODEL  │──▶│ EVALUATE │
  └─────────┘   └──────────┘   └─────────┘   └────────┘   └──────────┘
     01–01         02–02          03–10        11–30        14–15, 22, 25
                                                                 │
                        ┌────────────────────────────────────────┘
                        ▼
              ┌───────────────────────────────┐
              │  TEXT · GRAPHS · VISUALS · EDA │  31–40
              └───────────────────────────────┘
```

---

## 🗂️ The Experiments

<table>
<tr><td>

### 📥 Module 1 — Data Handling
Getting bytes off disk and into a clean `DataFrame`.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 01 | [1.py](1.py) | 📄 Import & export — CSV, Excel, JSON |
| 02 | [2.py](2.py) | 🧹 Preprocessing — missing values, duplicates, inconsistencies |
| 08 | [8.py](8.py) | 🔧 Manipulate & transform with Pandas |

</td></tr>
<tr><td>

### 📐 Module 2 — Statistics & Probability
The numbers behind the numbers.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 03 | [3.py](3.py) | 🧮 Mean, median, mode, variance, std. deviation, covariance |
| 04 | [4.py](4.py) | 🔗 Covariance & correlation matrices |
| 05 | [5.py](5.py) | 🔔 Univariate & multivariate normal distributions |
| 06 | [6.py](6.py) | ⚖️ Hypothesis testing with SciPy |
| 07 | [7.py](7.py) | 📏 Confidence intervals for population parameters |

</td></tr>
<tr><td>

### 📈 Module 3 — Visualization
Making the data admit what it's hiding.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 09 | [9.py](9.py) | 🎨 Matplotlib & Seaborn basics |
| 10 | [10.py](10.py) | 📊 Bar, histogram, pie, box, scatter, heatmap |
| 37 | [37.py](37.py) | 🖱️ Interactive charts with Plotly |
| 38 | [38.py](38.py) | 🕸️ Pair plots & multidimensional views |
| 39 | [39.py](39.py) | 🔍 Full EDA on a real-world dataset |

</td></tr>
<tr><td>

### 📉 Module 4 — Regression
Fitting a line, then fitting it responsibly.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 11 | [11.py](11.py) | ➖ Simple Linear Regression (Scikit-learn) |
| 12 | [12.py](12.py) | ➕ Multiple Linear Regression + evaluation |
| 13 | [13.py](13.py) | 🎚️ Ridge & Lasso (L2 / L1 regularization) |

</td></tr>
<tr><td>

### 🎯 Module 5 — Classification
Six algorithms, one shootout.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 14 | [14.py](14.py) | ✂️ Train-test split & cross-validation |
| 15 | [15.py](15.py) | 🧾 Confusion matrix, accuracy, precision, recall, F1, ROC-AUC |
| 16 | [16.py](16.py) | 👟 k-Nearest Neighbors |
| 17 | [17.py](17.py) | 🌳 Decision Tree |
| 18 | [18.py](18.py) | 🛡️ Support Vector Machine |
| 19 | [19.py](19.py) | 🌲 Random Forest |
| 20 | [20.py](20.py) | 🎲 Naïve Bayes |
| 21 | [21.py](21.py) | 🔀 Logistic Regression (binary) |
| 22 | [22.py](22.py) | 🏁 Compare all classifiers on one dataset |

</td></tr>
<tr><td>

### 🧩 Module 6 — Clustering
No labels. Find the structure anyway.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 23 | [23.py](23.py) | ⭕ K-Means |
| 24 | [24.py](24.py) | 🌿 Hierarchical clustering + dendrogram |
| 25 | [25.py](25.py) | 📋 Compare clusterings (silhouette, Davies-Bouldin, …) |

</td></tr>
<tr><td>

### 💡 Module 7 — Recommenders & Dimensionality Reduction
Fewer dimensions, better suggestions.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 26 | [26.py](26.py) | 👥 Collaborative filtering |
| 27 | [27.py](27.py) | 🏷️ Content-based recommendation |
| 28 | [28.py](28.py) | 🔢 Singular Value Decomposition (SVD) |
| 29 | [29.py](29.py) | 🎯 Principal Component Analysis (PCA) |
| 30 | [30.py](30.py) | ⚔️ PCA vs. SVD |

</td></tr>
<tr><td>

### 📝 Module 8 — Text Mining
Words in, vectors out.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 31 | [31.py](31.py) | ✂️ Tokenization, stop-word removal, stemming |
| 32 | [32.py](32.py) | 🔎 TF-IDF vectorization for information retrieval |
| 33 | [33.py](33.py) | 📐 Cosine similarity between documents |

</td></tr>
<tr><td>

### 🕸️ Module 9 — Social Network Analysis
Nodes, edges, and the cliques between them.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 34 | [34.py](34.py) | 🔵 Build & analyze graphs with NetworkX |
| 35 | [35.py](35.py) | 🏘️ Community detection |
| 36 | [36.py](36.py) | ✂️ Graph partitioning & neighborhood properties |

</td></tr>
<tr><td>

### 🏆 Module 10 — Capstone

| # | File | Experiment |
|:-:|:-----|:-----------|
| 40 | [40.py](40.py) | 🚀 End-to-end application — preprocess → visualize → model → evaluate → predict |

</td></tr>
</table>

---

## 🚀 Quick Start

```bash
cd ~/Programs/DS

python3 1.py          # run any experiment directly
```

Each file is standalone. Open it, read the `# N.` header at the top, run it — no imports
between files, no setup script, no order you have to follow.

> ⚠️ Use **`python3`**, not `python`. On this machine `python` is Python 3.10 with nothing
> installed — see [Requirements](#-requirements).

<details>
<summary>💻 What experiment 1 prints</summary>

<br>

```console
$ python3 1.py
CSV Data:
       Name  Age
0    Alice   25
1      Bob   30
2  Charlie   35
```

</details>

---

## 📦 Requirements

Everything below is **already installed** — this section is here for a fresh machine.

| Package | Version | Powers |
|---------|:-------:|--------|
| `pandas` | ✅ 3.0.1 | 1, 2, 8, 39, 40 |
| `numpy` | ✅ 2.3.4 | almost everything |
| `openpyxl` | ✅ 3.1.5 | Excel I/O in 1 |
| `scipy` | ✅ 1.18.0 | 5, 6, 7, 24 |
| `matplotlib` | ✅ 3.11.1 | 4, 9, 10, 24, 38, 39 |
| `seaborn` | ✅ 0.13.2 | 9, 10, 38, 39 |
| `scikit-learn` | ✅ 1.9.0 | 11–30, 32, 33, 40 |
| `plotly` | ✅ 6.9.0 | 37 |
| `networkx` | ✅ 3.6.1 | 34, 35, 36 |
| `nltk` | ✅ 3.10.2 | 31 |

<details>
<summary><b>🔁 Reinstalling from scratch</b></summary>

<br>

```bash
python3 -m pip install pandas numpy openpyxl scipy matplotlib \
                       seaborn scikit-learn plotly networkx nltk
```

NLTK also needs its corpora downloaded once, before experiment 31:

```bash
python3 -c "import nltk; nltk.download('punkt'); nltk.download('punkt_tab'); nltk.download('stopwords'); nltk.download('wordnet')"
```

</details>

### ⚠️ Use `python3 -m pip`, never bare `pip`

This machine has **two Pythons**, and the shortcuts point at different ones:

| Command | Resolves to | |
|---------|-------------|---|
| `python3` | Framework **3.14** | ✅ where every package lives — run scripts with this |
| `pip` → `python` → `python3.10` | Homebrew **3.10** | ❌ empty, installs land where nothing runs |

Install with bare `pip` and the packages vanish into 3.10 while `python3 1.py` keeps
reporting `ModuleNotFoundError`. Prefixing with `python3 -m` guarantees the installer and the
interpreter are the same one:

```bash
python3 -m pip install <package>      # ✅ always
pip install <package>                 # ❌ wrong Python
```

<details>
<summary>🔐 If NLTK downloads fail with <code>CERTIFICATE_VERIFY_FAILED</code></summary>

<br>

The python.org framework build ships without root certificates. Run the bundled fixer once:

```bash
"/Applications/Python 3.14/Install Certificates.command"
```

</details>

---

## 🗃️ About Datasets

**You don't need to download anything.** Every experiment can be run on data that's generated
or bundled, in roughly three flavours:

| Source | How | Used by |
|--------|-----|---------|
| 🔨 **Hand-built** | `pd.DataFrame({...})` written inline | 1, 2, 3, 8 |
| 🎰 **Synthetic** | `np.random.*`, `make_classification`, `make_blobs` | 4–7, 11–14, 23–25 |
| 📦 **Built into Scikit-learn** | `load_iris()`, `load_wine()`, `load_breast_cancer()`, `load_diabetes()` | 15–22, 26–30, 38–40 |

The Scikit-learn loaders ship inside the package — offline, no download, no API key:

```python
from sklearn.datasets import load_iris
X, y = load_iris(return_X_y=True)
```

Reach for a real CSV (Titanic, housing prices, …) only if experiment 39 or 40 asks you for one
specifically. Drop it in this folder and load it by filename.

---

## 📝 File Format

Every file opens with its numbered question, verbatim from the lab manual, and leaves the rest
of the page for you:

```python
# 17. Write a Python program to implement Decision Tree classification.

# ← your code goes here
```

The header comment is the contract — keep it, and the file stays self-describing when it lands
in a lab record.

---

## ⚠️ Files Experiment 1 Leaves Behind

Running [1.py](1.py) writes three files into the working directory:

```
data.csv    data.json    data.xlsx
```

That's the point of the exercise — it exports, then reads them back. Clean up with:

```bash
rm -f data.csv data.json data.xlsx
```

---

<div align="center">

### 🎓 Department of CSE · RSET

**Educational use.** The header is the question — the answer should be yours.

<br>

![Made with Python](https://img.shields.io/badge/Made%20with-Python-3776AB?style=flat-square&logo=python&logoColor=white)
![Pandas](https://img.shields.io/badge/Pandas-150458?style=flat-square&logo=pandas&logoColor=white)
![NumPy](https://img.shields.io/badge/NumPy-013243?style=flat-square&logo=numpy&logoColor=white)
![SciPy](https://img.shields.io/badge/SciPy-8CAAE6?style=flat-square&logo=scipy&logoColor=white)
![scikit-learn](https://img.shields.io/badge/scikit--learn-F7931E?style=flat-square&logo=scikit-learn&logoColor=white)
![Plotly](https://img.shields.io/badge/Plotly-3F4F75?style=flat-square&logo=plotly&logoColor=white)

</div>
