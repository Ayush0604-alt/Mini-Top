# 🖥️ MonHealth - Linux System Monitor

MonHealth is a lightweight, real-time system monitoring tool built in **C++** that displays CPU usage, memory usage, and running processes using the Linux `/proc` filesystem.

---

## 🚀 Features

* 📊 Real-time CPU usage calculation
* 💾 Memory usage tracking
* 📋 Process listing (PID + Name)
* ⚡ Lightweight and fast (no external libraries)
* 🛠️ Modular C++ design (separate CPU, Memory, Process modules)
* ⚙️ Built using **CMake**
* 🐳 Docker support for easy setup

---

## 🧠 How It Works

MonHealth reads system-level data directly from the Linux kernel via:

* `/proc/stat` → CPU statistics
* `/proc/meminfo` → Memory usage
* `/proc/[pid]/comm` → Process names

This makes it similar to tools like `top`, but implemented from scratch in C++.

---

## 📁 Project Structure

```
MonHealth/
│
├── src/
│   ├── main.cpp
│   ├── cpu.cpp / cpu.h
│   ├── memory.cpp / memory.h
│   ├── process.cpp / process.h
│
├── CMakeLists.txt
├── Dockerfile
├── .gitignore
└── README.md
```

---

## ⚙️ Requirements

* Linux / WSL / Docker
* C++17 compatible compiler
* CMake

---

## 🔧 Build & Run (Manual)

```bash
git clone https://github.com/Ayush0604-alt/Mini-Version-Top.git
cd Mini-Version-Top

mkdir build
cd build
cmake ..
make

./MonHealth
```

---

## 🐳 Run with Docker (Recommended)

Follow these steps to run MonHealth using Docker:

---

### 🔹 Step 1: Clone the repository

```bash
git clone https://github.com/Ayush0604-alt/Mini-Version-Top.git
cd Mini-Version-Top
```

---

### 🔹 Step 2: Build Docker image

```bash
docker build -t monhealth .
```

👉 This creates a Docker image named **monhealth**

---

### 🔹 Step 3: Run the container

```bash
docker run --rm -it --pid=host --init monhealth
```

---

## 🔑 Explanation of flags

* `--rm` → Automatically removes the container after it stops
* `-it` → Runs in interactive terminal mode
* `--pid=host` → Allows access to host system processes
* `--init` → Ensures proper signal handling (Ctrl + C works)

---

## ⚠️ Important Notes

* Run commands in the folder where **Dockerfile** exists
* Works only on **Linux / WSL / EC2**
* If using AWS EC2, ensure Docker is installed

---

## 🧪 Example (AWS EC2)

```bash
git clone https://github.com/Ayush0604-alt/Mini-Version-Top.git
cd Mini-Version-Top
docker build -t monhealth .
docker run --rm -it --pid=host --init monhealth
```


### 🔑 Explanation of flags

* `--rm` → removes container after exit
* `-it` → interactive terminal
* `--pid=host` → access host system processes
* `--init` → proper signal handling (Ctrl+C)

---

## 📊 Sample Output

```
===== MonHealth System Monitor =====

CPU Usage:    3.45%
Memory Usage: 11.00%

PID    NAME
1      systemd
672    bash
753    docker
...
```

---

## ⚠️ Notes

* Works only on **Linux-based systems** (uses `/proc` filesystem)
* Use Docker with `--pid=host` to view actual system processes

---

## 💡 Future Improvements

* Sort processes by CPU usage
* Show top N processes
* Interactive UI (like `top`)
* Better terminal handling (ncurses)

---

## 👨‍💻 Author

**Ayush Jha**
Computer Science Student | Systems Programming Enthusiast

---

## ⭐ Support

If you found this useful, consider giving it a ⭐ on GitHub!
