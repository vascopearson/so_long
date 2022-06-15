# so_long

## 🗣️ About this project

>This project is a very small 2D game.<br/>
>Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.

For detailed information, refer to the [**subject of this project**](https://github.com/vascopearson/so_long/blob/master/en.subject.pdf).

## 🛠️ Usage

### Requirements

The project is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.<br/>
It also uses the **mlx** library which is a graphical library made at 42. This library is already complied in the code and nothing needs to be done to use it.

### Instructions

**1. Compiling**

To compile, run:

```shell
$ cd path/to/so_long && make all
$./so_long maps/map1.ber
```
You can choose any map in the maps directory or create your own map in a .ber file.

**2. Playing the game**

Use the W,A,S,D keys to move.<br/>
You can only exit through the door once you have collected all the colectibles.<br/>
You can exit the game without completing it by pressing **esc** or the top left red cross on the window.
