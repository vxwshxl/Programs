<div align="center">

# 📊 Introduction to Data Science Lab

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=22&duration=3000&pause=800&color=00B4D8&center=true&vCenter=true&width=650&lines=Import+%E2%86%92+Clean+%E2%86%92+Explore+%E2%86%92+Model+%E2%86%92+Evaluate;40+experiments%2C+one+pipeline%2C+start+to+finish;Pandas+%C2%B7+NumPy+%C2%B7+SciPy+%C2%B7+Scikit-learn+%C2%B7+Seaborn" alt="Typing SVG" />

![Language](https://img.shields.io/badge/Python-3.14-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Subject](https://img.shields.io/badge/CSE022D715-Data%20Science%20Lab-00B4D8?style=for-the-badge)
![Semester](https://img.shields.io/badge/B.Tech-5th%20Sem-success?style=for-the-badge)
![Dept](https://img.shields.io/badge/Dept.%20of%20CSE-RSET-maroon?style=for-the-badge)

![Experiments](https://img.shields.io/badge/Experiments-40-blueviolet?style=flat-square)
![Status](https://img.shields.io/badge/Progress-13%20%2F%2040-orange?style=flat-square)
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
| 01 | [1.py](1/1.py) | 📄 Import & export — CSV, Excel, JSON |
| 02 | [2.py](2/2.py) | 🧹 Preprocessing — missing values, duplicates, inconsistencies |
| 08 | [8.py](8/8.py) | 🔧 Manipulate & transform with Pandas |

</td></tr>
<tr><td>

### 📐 Module 2 — Statistics & Probability
The numbers behind the numbers.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 03 | [3.py](3/3.py) | 🧮 Mean, median, mode, variance, std. deviation, covariance |
| 04 | [4.py](4/4.py) | 🔗 Covariance & correlation matrices |
| 05 | [5.py](5/5.py) | 🔔 Univariate & multivariate normal distributions |
| 06 | [6.py](6/6.py) | ⚖️ Hypothesis testing with SciPy |
| 07 | [7.py](7/7.py) | 📏 Confidence intervals for population parameters |

</td></tr>
<tr><td>

### 📈 Module 3 — Visualization
Making the data admit what it's hiding.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 09 | [9.py](9/9.py) | 🎨 Matplotlib & Seaborn basics |
| 10 | [10.py](10/10.py) | 📊 Bar, histogram, pie, box, scatter, heatmap |
| 37 | [37.py](37/37.py) | 🖱️ Interactive charts with Plotly |
| 38 | [38.py](38/38.py) | 🕸️ Pair plots & multidimensional views |
| 39 | [39.py](39/39.py) | 🔍 Full EDA on a real-world dataset |

</td></tr>
<tr><td>

### 📉 Module 4 — Regression
Fitting a line, then fitting it responsibly.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 11 | [11.py](11/11.py) | ➖ Simple Linear Regression (Scikit-learn) |
| 12 | [12.py](12/12.py) | ➕ Multiple Linear Regression + evaluation |
| 13 | [13.py](13/13.py) | 🎚️ Ridge & Lasso (L2 / L1 regularization) |

</td></tr>
<tr><td>

### 🎯 Module 5 — Classification
Six algorithms, one shootout.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 14 | [14.py](14/14.py) | ✂️ Train-test split & cross-validation |
| 15 | [15.py](15/15.py) | 🧾 Confusion matrix, accuracy, precision, recall, F1, ROC-AUC |
| 16 | [16.py](16/16.py) | 👟 k-Nearest Neighbors |
| 17 | [17.py](17/17.py) | 🌳 Decision Tree |
| 18 | [18.py](18/18.py) | 🛡️ Support Vector Machine |
| 19 | [19.py](19/19.py) | 🌲 Random Forest |
| 20 | [20.py](20/20.py) | 🎲 Naïve Bayes |
| 21 | [21.py](21/21.py) | 🔀 Logistic Regression (binary) |
| 22 | [22.py](22/22.py) | 🏁 Compare all classifiers on one dataset |

</td></tr>
<tr><td>

### 🧩 Module 6 — Clustering
No labels. Find the structure anyway.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 23 | [23.py](23/23.py) | ⭕ K-Means |
| 24 | [24.py](24/24.py) | 🌿 Hierarchical clustering + dendrogram |
| 25 | [25.py](25/25.py) | 📋 Compare clusterings (silhouette, Davies-Bouldin, …) |

</td></tr>
<tr><td>

### 💡 Module 7 — Recommenders & Dimensionality Reduction
Fewer dimensions, better suggestions.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 26 | [26.py](26/26.py) | 👥 Collaborative filtering |
| 27 | [27.py](27/27.py) | 🏷️ Content-based recommendation |
| 28 | [28.py](28/28.py) | 🔢 Singular Value Decomposition (SVD) |
| 29 | [29.py](29/29.py) | 🎯 Principal Component Analysis (PCA) |
| 30 | [30.py](30/30.py) | ⚔️ PCA vs. SVD |

</td></tr>
<tr><td>

### 📝 Module 8 — Text Mining
Words in, vectors out.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 31 | [31.py](31/31.py) | ✂️ Tokenization, stop-word removal, stemming |
| 32 | [32.py](32/32.py) | 🔎 TF-IDF vectorization for information retrieval |
| 33 | [33.py](33/33.py) | 📐 Cosine similarity between documents |

</td></tr>
<tr><td>

### 🕸️ Module 9 — Social Network Analysis
Nodes, edges, and the cliques between them.

| # | File | Experiment |
|:-:|:-----|:-----------|
| 34 | [34.py](34/34.py) | 🔵 Build & analyze graphs with NetworkX |
| 35 | [35.py](35/35.py) | 🏘️ Community detection |
| 36 | [36.py](36/36.py) | ✂️ Graph partitioning & neighborhood properties |

</td></tr>
<tr><td>

### 🏆 Module 10 — Capstone

| # | File | Experiment |
|:-:|:-----|:-----------|
| 40 | [40.py](40/40.py) | 🚀 End-to-end application — preprocess → visualize → model → evaluate → predict |

</td></tr>
</table>

---

## 🚀 Quick Start

Every experiment lives in **its own numbered folder** — experiment 11 is `11/11.py`, not `11.py`.

```bash
cd ~/Programs/DS

python3 11/11.py          # run experiment 11
python3 1/1.py            # run experiment 1
```

Or step into the folder first. Do it this way for **experiment 1**, so the files it writes
land in `1/` instead of the repo root:

```bash
cd ~/Programs/DS/1
python3 1.py
```

Each file is standalone. Open it, read the `# N.` header at the top, run it — no imports
between files, no setup script, no order you have to follow.

> ⚠️ Use **`python3`**, not `python`. On this machine `python` is Python 3.10 with nothing
> installed — see [Requirements](#-requirements).

### 🖼️ Experiments that open plot windows

Anything using Matplotlib or Seaborn (**4, 5, 9, 10, 11, 12, 13, 24, 38, 39**) pauses at
`plt.show()` and waits. **Close the window to let the script finish** — it has not frozen.

Experiments with more than one chart draw them all onto a **single figure** with
`plt.subplots()`, so everything appears at once and there is one window to close:

| Experiment | Layout |
|:-:|:--|
| 4 | 1 × 2 — covariance, correlation |
| 5 | 1 × 2 — univariate, multivariate |
| 9 | 1 × 2 — Matplotlib, Seaborn |
| 10 | 2 × 3 — bar, histogram, pie, box, scatter, heatmap |
| 13 | 1 × 3 — coefficients, Ridge path, Lasso path |

> 💡 Calling `plt.show()` after *every* chart is what forces you to close six windows one
> after another. Build the axes up front, then show once at the end.

Running over SSH, or just want the printed numbers without the windows:

```bash
MPLBACKEND=Agg python3 13/13.py     # skip the plots, keep the output
```

<details>
<summary>▶️ Run every finished experiment in one go</summary>

<br>

```bash
cd ~/Programs/DS

for d in $(ls -d */ | sort -n); do
  n=${d%/}
  [ -f "$n/$n.py" ] || continue
  echo "───── Experiment $n ─────"
  (cd "$n" && MPLBACKEND=Agg python3 "$n.py")
done
```

`MPLBACKEND=Agg` keeps it from stopping at every plot, and the `cd` keeps stray output files
in their own folder.

</details>

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

Check what this machine actually has, and what it is missing:

```bash
python3 -m pip list | grep -iE "pandas|numpy|openpyxl|scipy|matplotlib|seaborn|scikit-learn|plotly|networkx|nltk"
```

Anything that does not print is missing — install just that one:

```bash
python3 -m pip install <package>
```

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

### 🕷️ Running in Spyder 6

Spyder 6 does **not** use the `python3` above. The installer ships its own bundled conda
environment, so packages installed for `python3` are invisible to it:

```
~/Library/spyder-6/envs/spyder-runtime        Python 3.12.11
```

Out of the box it has pandas, numpy, scipy and matplotlib, but **not** seaborn, scikit-learn,
plotly, networkx or nltk — so experiment 10 fails at `import seaborn` with
`ModuleNotFoundError`. That environment has no `pip`, so install with the bundled conda:

```bash
~/Library/spyder-6/bin/conda install \
  -p ~/Library/spyder-6/envs/spyder-runtime \
  -c conda-forge -y \
  seaborn scikit-learn plotly networkx nltk
```

Check what the Spyder environment can see:

```bash
~/Library/spyder-6/envs/spyder-runtime/bin/python -m pip list 2>/dev/null || \
~/Library/spyder-6/bin/conda list -p ~/Library/spyder-6/envs/spyder-runtime
```

> ⚠️ Install with **conda**, not pip — `spyder-runtime` ships without pip, and pulling pip in
> to mix installers is what breaks the environment. Reinstalling or updating Spyder can reset
> this environment, in which case run the command again.

Two Spyder details worth knowing:

- **Plots land in the Plots pane**, not a window, because Spyder defaults to the `Inline`
  backend (bottom-right of the status bar). One figure with subplots therefore shows as one
  image — for a separate window per figure, switch to `Tools ▸ Preferences ▸ IPython console
  ▸ Graphics ▸ Backend: Automatic`.
- **Set the working directory** to the experiment's own folder (the box at the top right)
  before running experiment 1, or its `1.csv` / `1.json` / `1.xlsx` land wherever Spyder
  happened to be pointing.

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

Running [1.py](1/1.py) writes three files **into whatever folder you ran it from**:

```
1.csv    1.json    1.xlsx
```

That's the point of the exercise — it exports, then reads them back. The filenames are relative,
so run it as `cd 1 && python3 1.py` to keep them in `1/` instead of scattering them across the
repo root. They are already committed, so re-running simply overwrites them — nothing to clean up.

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
