
# The Unfair Game (T.U.G.)(by Sebastiaan and Jeffrey)

## Assignment for Software design C/C++ and QT

This project is part of the Software design C/C++ and QT class.
It is lectured by [Wouter Groeneveld](https://github.com/wgroeneveld). The goal of this project
is to make a GBA game in C++. To do so we start from the [gba-sprite-engine](https://github.com/wgroeneveld/gba-sprite-engine/).

## Minimum requirements
<details>
<summary>Click to see the minimum requirements</summary>
* Code on GitHub with an MIT licence
* Start from gba-sprite-engine (previously mentioned)
* If used, mention sources.
* It has to compile.
* README.md with a short functional description of the game.
* Sketch of the domain model with explanatory text.
* Timespent.csv with separated registered time spent in hours.
</details>

## T.U.G.
The Unfair Game is a game based on Unfair Mario. 
The main character his name is Gerard and his evil counterpart is the Saaientist (Scientist).
<details>
<summary>Click to see Gerard and the Saaientist</summary>
![Gerard](https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/sprite/Gerard/Gerard-large.png)
![Scientist](https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/sprite/Saaientist/Mad%20Saaientist%20large.png)
</details>

When first loading the game, a start scene is previewed with the current amount of deaths
(yes, it has a counter and you will find out why) and instruction how to load the next scene. <br/>
<img src="https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/img/unfairgame_startscreen.png" width="300" height="200">

When pressing start, the next scene is loaded.
In this scene poor Gerard has to survive the evil things that spawn trying to kill Gerard.<br/>
![Gif](https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/img/unfairgame_unfairscene.gif)

If you somehow make it into the final boss fight, be prepared for a fight!
While trying to dodge the massive amount of testtubes or fireballs he throws at you, pressing START will spawn a bomb. This bomb has to explode while the scientist is near it in order to damage him!  <br/>
![Bossfight](https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/img/unfairgame_bossfight.gif)

## Authors

* *Wouter Groeneveld*       - Lecturer  - [GitHub](https://github.com/wgroeneveld)
* *Jeffrey Gorissen*        - Student   - [GitHub](https://github.com/J3G0)
* *Sebastiaan Vanspauwen*   - Student   - [GitHub](https://github.com/SebastiaanVanspauwen)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

* Piskel for providing a great tool to create our own sprites
* ...