#!/bin/bash

# Get parameters
while getopts v:q:n:t:f:d option
do

    case "${option}"
    in
	v)velocity=${OPTARG};;
	q)quotient=${OPTARG};;
	n)refraction=${OPTARG};;
	t)isTorus=${OPTARG};;
	f)frecuency=${OPTARG};;
	d)draws=${OPTARG};;
    esac
done


# Default parameters
if [ -z "$velocity" ]; then
    velocity=5e-4
fi

if [ -z "$quotient" ]; then
    quotient=0.99
fi

if [ -z "$refraction" ]; then
    refraction=1.3325
fi

if [ -z "$isTorus" ]; then
    isTorus=true
fi

if [ -z "$frecuency" ]; then
    frecuency=150
fi

if [ -z "$draws" ]; then
    draws=50
fi


# Print parameters
echo "Particle velocity:   $velocity"
echo "Velocities quotient: $quotient"
echo "Refraction index:    $refraction"
echo "Print Torus:         $isTorus"
echo "Draws frecuency:     $frecuency"
echo "Draws shown:         $draws"


# Set parameters in file
sed -i "s%^double particleVelocity.*%double particleVelocity = ${velocity};%" code.cpp
sed -i "s%^double velocitiesQuotient.*%double velocitiesQuotient = ${quotient};%" code.cpp
sed -i "s%^double refractionIndex.*%double refractionIndex = ${refraction};%" code.cpp
sed -i "s%^Torus torus.*%Torus torus(${isTorus});%" code.cpp
sed -i "s%^int wavesFrecuency.*%int wavesFrecuency = ${frecuency};%" code.cpp
sed -i "s%^unsigned int wavesDraws.*%unsigned int wavesDraws = ${draws};%" code.cpp


# Compilation process
if [ ! -d build ]; then
    mkdir build
fi
cd build/
cmake ../
make
cd ../


# Excution process
time ./build/x.code
rm ./build/x.code
