# 📈 Stock Market Simulator (C)

A simple command-line based **Stock Market Simulator** written in C that allows users to buy and sell stocks, track their portfolio, and simulate price fluctuations.

---

## 🚀 Features

- 📊 View available stocks with real-time prices  
- 💰 Buy stocks based on available balance  
- 💸 Sell owned stocks  
- 📁 View portfolio (holdings + balance)  
- 🔄 Simulate stock price updates using randomness  
- 🧮 Basic portfolio management system  

---

## 🛠️ Tech Stack

- Language: **C**
- Concepts Used:
  - Structures (`struct`)
  - Arrays
  - Functions
  - Pointers
  - Random number generation (`rand()`)
  - Standard I/O

---
stock-simulator/
│── main.c
│── README.md


---

## ⚙️ How It Works

- The program initializes **10 predefined stocks** with base prices.
- The user starts with a balance of **₹100000**.
- Stock prices fluctuate randomly when updated.
- Users can:
  - Buy stocks (if balance allows)
  - Sell stocks (if owned)
  - Track portfolio performance

---

## 🖥️ Menu Options

View Stocks
Buy Stock
Sell Stock
View Portfolio
Update Stock Prices
Exit


---

## ▶️ How to Run

### Step 1: Compile
```bash
gcc main.c -o simulator

## 📂 Project Structure
./simulator
--- Stock Market Simulator ---
1. View Stocks
2. Buy Stock
3. Sell Stock
4. View Portfolio
5. Update Stock Prices
0. Exit
