# Libft-God (2026 Edition) 🚀

**Libft-God** is the ultimate, high-performance testing suite for the 42 school `libft` project. Built upon the legacy of the industry-standard testers, this "God" edition has been massively expanded to provide the most rigorous validation possible for today's standards. It is the definitive tool for students who aim not just to pass, but to achieve perfection.

---

## 🚀 Why "Libft-God"?

While based on the legendary *libft-war-machine*, **Libft-God** is a major evolution designed for the modern 42 curriculum. We have **tripled the number of unit tests**, shifting the focus from simple functionality to extreme **edge-case robustness**.

### 📈 Unrivaled Test Coverage
Every function is subjected to a relentless barrage of tests. We don't just check if `ft_atoi` converts "42"; we check how it handles `INT_MIN`, overflowing strings, multiple signs, and weird whitespace combinations.
*   **Part 1 (Libc):** 100% behavior matching with original `libc`.
*   **Part 2 (Additional):** Strict protection against NULL and empty inputs.
*   **Part 3 (Linked Lists):** Exhaustive memory leak and pointer manipulation checks.
*   **Extra Functions:** Support for over 15+ additional utility functions used in advanced 42 projects.

### 🧪 Edge-Case Obsession
We test what others ignore:
- **NULL Pointers:** How does your code react to unexpected NULLs?
- **Buffer Boundaries:** Testing the exact byte before and after limits.
- **Integer Extremes:** Full coverage for `INT_MIN`, `INT_MAX`, and `unsigned` overflows.
- **Empty Inputs:** Handing `""`, size `0`, and empty lists gracefully.

### ⚡ Optimized Performance: Fast Mode
Large test suites can be slow. Libft-God introduces **Turbo Mode (`-fast`)**, an optimized engine that runs memory leak detection (Valgrind/Leaks) in a "one-shot" batch per function. This reduces execution time by up to **90%** while maintaining 100% accuracy.

---

## ✨ Key Features

- **🍎🐧 True Cross-Platform:** Seamlessly detects your OS. Uses native **Leaks** on macOS and **Valgrind** on Linux. No special compilation flags needed—it works with your standard `cc`.
- **🎨 God-Tier UI:** A modern, color-coded terminal interface with real-time progress bars and beautifully formatted result tables.
- **📏 Norminette 3.x Ready:** Fully integrated with the latest Norminette.
- **🚫 Forbidden Function Scanner:** Scans your binary to ensure you haven't used unauthorized functions like `printf` or `string.h` where not allowed.
- **🛠️ Makefile Stress-Test:** Validates `all`, `clean`, `fclean`, and `re` rules to ensure your build system is production-ready.
- **📜 Deepthought Logs:** Generates a detailed `deepthought` log file for every run, allowing you to debug complex failures with ease.

---

## 🚀 Getting Started

### 1. Installation
Clone the tester into a directory alongside or inside your `libft`:
```bash
git clone https://github.com/Pleb-42/libft-god.git
```

### 2. Configuration
The tester needs to know where your source code is.
1. Create your configuration file:
   ```bash
   cp srcs/config_template.sh my_config.sh
   ```
2. Edit `my_config.sh` and set `PATH_LIBFT`:
   ```bash
   PATH_LIBFT="/path/to/your/libft"
   SRC_DIR="srcs" # If your .c files are in a subfolder
   HEADER_DIR="inc" # If your .h files are in a subfolder
   ```

### 3. Basic Execution
Run everything:
```bash
bash grademe.sh
```

Run a specific function:
```bash
bash grademe.sh ft_split
```

Run with **Turbo Mode** (High speed):
```bash
bash grademe.sh -fast
```

---

## 🛠️ Command Line Options

| Flag | Description |
| :--- | :--- |
| `-h`, `--help` | Display the manual. |
| `-fast` | **Turbo Mode:** Runs leak detection once per function (9x faster). |
| `-a`, `--about` | Display the **Pleb_42** tribute page and ASCII art. |
| `-n` | Skip **Norminette** check. |
| `-f` | Skip **Forbidden Functions** check. |
| `-m` | Execute a rigorous **Makefile** audit. |
| `-op1, -op2, -op3` | Run **ONLY** Part 1, Part 2, or Part 3. |
| `-p1, -p2, -p3` | **Exclude** Part 1, Part 2, or Part 3 from the run. |
| `-c` | Disable terminal **colors**. |
| `-d` | Use custom directory mode (for complex project structures). |

---

## 📁 Supported Functions

For a detailed list of every function and the specific edge cases we test, please refer to:
👉 **[Supported Functions Documentation](supported_functions.md)**

---

## 🏛️ Credits and History

**Libft-God** is a community project developed and maintained by the **Pleb_42** organization—a group of students dedicated to building high-quality tools for the 42 community.

### Historical Lineage
This project is an evolution of several legendary tools. We acknowledge and thank the creators who came before us:
- **[libft-war-machine](https://github.com/0x050f/libft-war-machine)** by **@0x050f** (The primary foundation of this version).
- Improvements and logic from **@lmartin**.
- The original **Libftest** by **@jtoty**.

### The Pleb_42 Initiative
The **Pleb_42** version (Libft-God) was created to modernize these tools for the 2026 curriculum, fixing bugs in macOS leak detection, updating Norminette compatibility, and massively expanding test coverage.

---
*Disclaimer: This tester is a tool for excellence. Use it to refine your code, but remember that the ultimate validation is your own understanding and the official 42 evaluation.*
