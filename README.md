
# The Unfair Game (T.U.G.)(by Sebastiaan and Jeffrey)

## Assignment for Software design C/C++ and QT

This project is part of the Software design C/C++ and QT class.
It is lectured by [Wouter Groeneveld](https://github.com/wgroeneveld). The goal of this project
is to make a GBA game in C++. To do so we start from the [gba-sprite-engine](https://github.com/wgroeneveld/gba-sprite-engine/).

## Minimum requirements
<details>
<summary>Click to see the minimum requirements</summary>

* Code on GitHub with an MIT [LICENSE](LICENSE)

* Start from [gba-sprite-engine](https://github.com/wgroeneveld/gba-sprite-engine/)

* If used, mention sources.

* It has to compile.

* [README](README.md) with a short functional description of the game (What you are reading now).

* Sketch of the domain model with explanatory text.

* Timespent.csv with separated registered time spent in hours.

</details>

## T.U.G.
The Unfair Game is a game based on Unfair Mario. 
The main character his name is Gerard and his evil counterpart is the Saaientist (Scientist). The player
takes control of Gerard and has to find his way through the complex web the makes T.U.G. what it is, unfair.
When you finally found your way you will be met by the Saaientist (Dutch word joke as name - means as much as boring dude).
He is not what his name depicts of him. Will you defeat him?

<details>
<summary>Click to see Gerard</summary>
<img src="https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/sprite/Gerard/Gerard-large.png">
</details>

<details>
<summary>Click to see the Saaientist</summary>
<img src="https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/sprite/Saaientist/Mad%20Saaientist%20large.png">
</details>


<details>
<summary>Click to see more about T.U.G.</summary>
When first loading the game, a start scene shows the current amount of deaths
(yes, it has a counter and you will find out why) and instruction on how to load the next scene.
Furthermore, there are some encouraging messages after every death.<br/>
<img src="https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/img/unfairgame_startscreen.png" width="300" height="200">

When pressing start, the next scene is loaded.
In this scene poor Gerard has to survive the evil things that spawn trying to kill Gerard.<br/>
![Gif](https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/img/unfairscene.gif)

If you somehow make it into the final boss fight, be prepared for a fight!
While trying to dodge the massive amount of testtubes and/or fireballs he throws at you, pressing B will spawn a bomb. This bomb has to explode while the scientist is near it in order to damage him!  <br/>
The bossfight is accompanied by a fitting high-paced song:
[link](https://www.youtube.com/watch?v=wOFgh2IdnZI)
<br/>
![Bossfight](https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/img/bossfight2.gif)
</details>

## Authors

* *Wouter Groeneveld*       - Lecturer  - [GitHub](https://github.com/wgroeneveld)
* *Jeffrey Gorissen*        - Student   - [GitHub](https://github.com/J3G0)
* *Sebastiaan Vanspauwen*   - Student   - [GitHub](https://github.com/SebastiaanVanspauwen)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

* Piskel for providing a great tool to create our own sprites

## Known bugs
Sometimes a sprite isn't deleted correctly, which introduces a flicker.
such as this: <br/>
![Flicker](https://github.com/J3G0/gba-sprite-engine/blob/master/unfairGame/img/wtf.gif)
