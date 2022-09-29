# Cherenkov Animation

---

The Cherenkov Radiation is a lumminical physical phenomenon where a charge particle, e.g., electron, travel faster than light velocity on the media (**NOT vacumm**). These material must to be dielectric.

## Execution process

---

The execution is done with the `script.sh` file. This file receive multiple optional arguments:

- **Particle's velocity (v)**: Is the velocity of the particle in the media. The default value is 5e-4

- **Velocities quotient (q)**: Is the quotient between the light's velocity in the vacuum and the particle's velocity in the media. The default value is 0.99.

- **Refraction index (n)**: Is the media's refraction index. The default value is 1.3325 (water's refraction index).

- **Is Toroidal wave (t)**: Draw the light waves as torus if it is *true*, if *false* draw it as wire spheres. The default value is *true*.

- **Draws Frecuency (f)**: Draw the light waves sparsed in the given time frecuency. The default value is 150.

- **Waves Draws (d)**: Draws the number given of draws. The oldest waves are not painted. The default value is 50.

The command line for the correct execution is

```bash
bash script.sh -v velocity -q quotient -n refraction -t isTorus -f frecuency -d draws
```

All parameters are optional so can be executed with

```bash
bash script.sh
```
