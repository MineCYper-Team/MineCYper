*Designed with the tears of [Void01702](https://github.com/Void01702) and [JordanViknar](https://github.com/JordanViknar).*

---

# MineCYper : The "Ultimate" Minesweeper*

![License](https://img.shields.io/github/license/MineCYper-Team/MineCYper?color=green)
![Top language](https://img.shields.io/github/languages/top/MineCYper-Team/MineCYper?color=green)
![Commit activity](https://img.shields.io/github/commit-activity/m/MineCYper-Team/MineCYper?color=red)
![Repo size](https://img.shields.io/github/repo-size/MineCYper-Team/MineCYper)

Minesweeper in C, powered by your terminal. Made for the final computing project of CY Tech's Pré-ING1 year.

## I want to play this game straight from source ! What do I do ?
First things first, open a terminal. Oh and do that on Linux. There was no budget for Windows compatibility. *(There was no budget at all.)*

Next, you'd want to use *git* to clone this repository.
```bash
git clone https://github.com/MineCYper-Team/MineCYper
```
Go into the root of the repository.
```bash
cd MineCYper
```
Make sure you have *make* and *gcc*. Then run :
```bash
make run_release
```
to compile and immediately run it.

*There are other options present in the Makefile to accomodate your needs.*

## How do I play ?

### The actual game
Use the in-game tutorial, and if it's not enough, you can rely on [this French website](https://www.demineur-ligne.com/rules). Good luck if you don't know French !

### Prompts

*(No budget for mouse support either.)*

- Selecting a menu : enter the integer of the selection you wish to make.
- Selecting a square *(ingame)* : enter the coordinates of the square you wish to use in the A1 format.
- Selecting an action *(ingame)* : enter either R (to reveal a square) or F (to put a flag on it).

## Supported Features

| Features | Supported |
| ---- | ---- |
| Can do basic gameplay | ✓ |
| Can use Flags | ✓ |
| Can display time taken | ✓ |
| Can display fastest times | ✓ |
| Allows custom games | ✓ |
| In-game tutorial | ✓ |

---

*\*it is in the fact the ultimate Minesweeper if you remove literally every other option*
