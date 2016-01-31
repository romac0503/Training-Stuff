// HightMap.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <noise\noise.h>
#include "noiseutils.h"

using namespace noise;
using namespace std;

int main(int argc, char* argv[])
{
	//module::Perlin myModule;
	//myModule.SetOctaveCount(10);

	//utils::NoiseMap heightMap;
	//utils::NoiseMapBuilderSphere heightMapBuilder;
	//heightMapBuilder.SetSourceModule(myModule);
	//heightMapBuilder.SetDestNoiseMap(heightMap);
	//heightMapBuilder.SetDestSize(512, 256);
	//heightMapBuilder.SetBounds(-90.0, 90.0, -180.0, 180.0);
	//heightMapBuilder.Build();

	//utils::RendererImage renderer;
	//utils::Image image;
	//renderer.SetSourceNoiseMap(heightMap);
	//renderer.SetDestImage(image);
	//renderer.ClearGradient();
	//renderer.AddGradientPoint(-1.0000, utils::Color(0, 0, 128, 255)); // deeps
	//renderer.AddGradientPoint(-0.2500, utils::Color(0, 0, 255, 255)); // shallow
	//renderer.AddGradientPoint(0.0000, utils::Color(0, 128, 255, 255)); // shore
	//renderer.AddGradientPoint(0.0625, utils::Color(240, 240, 64, 255)); // sand
	//renderer.AddGradientPoint(0.1250, utils::Color(32, 160, 0, 255)); // grass
	//renderer.AddGradientPoint(0.3750, utils::Color(224, 224, 0, 255)); // dirt
	//renderer.AddGradientPoint(0.7500, utils::Color(128, 128, 128, 255)); // rock
	//renderer.AddGradientPoint(1.0000, utils::Color(255, 255, 255, 255)); // snow
	//renderer.EnableLight();
	//renderer.SetLightContrast(3.0);
	//renderer.SetLightBrightness(2.0);
	//renderer.Render();

	//utils::WriterBMP writer;
	//writer.SetSourceImage(image);
	//writer.SetDestFilename("tutorial.bmp");
	//writer.WriteDestFile();

	//return 0;

	/*module::RidgedMulti mountainTerrain;

	module::Billow baseFlatTerrain;
	baseFlatTerrain.SetFrequency(2.0);

	module::ScaleBias flatTerrain;
	flatTerrain.SetSourceModule(0, baseFlatTerrain);
	flatTerrain.SetScale(0.125);
	flatTerrain.SetBias(-0.75);

	module::Perlin terrainType;
	terrainType.SetFrequency(0.5);
	terrainType.SetPersistence(0.25);

	module::Select terrainSelector;
	terrainSelector.SetSourceModule(0, flatTerrain);
	terrainSelector.SetSourceModule(1, mountainTerrain);
	terrainSelector.SetControlModule(terrainType);
	terrainSelector.SetBounds(0, 1000);
	terrainSelector.SetEdgeFalloff(0.125);

	module::ScaleBias terrainScaler;
	terrainScaler.SetSourceModule(0, terrainSelector);
	terrainScaler.SetScale(375.0);
	terrainScaler.SetBias(375.0);


	module::Turbulence finalTerrain;
	finalTerrain.SetSourceModule(0, terrainScaler);
	finalTerrain.SetFrequency(4.0);
	finalTerrain.SetPower(0.125);

	utils::NoiseMap heightMap;
	utils::NoiseMapBuilderPlane heightMapBuilder;
	heightMapBuilder.SetSourceModule(finalTerrain);
	heightMapBuilder.SetDestNoiseMap(heightMap);
	heightMapBuilder.SetDestSize(513, 513);
	heightMapBuilder.SetBounds(6.0, 10.0, 1.0, 5.0);
	heightMapBuilder.Build();

	utils::WriterTER writer;
	writer.SetSourceNoiseMap(heightMap);
	writer.SetDestFilename("terrain.ter");
	writer.SetMetersPerPoint(15);
	writer.WriteDestFile();*/

	//utils::RendererImage renderer;
	//utils::Image image;
	//renderer.SetSourceNoiseMap(heightMap);
	//renderer.SetDestImage(image);
	//renderer.ClearGradient();
	//renderer.AddGradientPoint(-1.00, utils::Color(32, 160, 0, 255)); // grass
	//renderer.AddGradientPoint(-0.25, utils::Color(224, 224, 0, 255)); // dirt
	//renderer.AddGradientPoint(0.25, utils::Color(128, 128, 128, 255)); // rock
	//renderer.AddGradientPoint(1.00, utils::Color(255, 255, 255, 255)); // snow
	//renderer.EnableLight();
	//renderer.SetLightContrast(3.0);
	//renderer.SetLightBrightness(2.0);
	//renderer.Render();

	//utils::WriterBMP writer;
	//writer.SetSourceImage(image);
	//writer.SetDestFilename("tutorial.bmp");
	//writer.WriteDestFile();


	/*module::Perlin myModule;
	double value = myModule.GetValue(14.50, 20.25, 75.75);
	cout << value << std::endl;
	cin.get();
	return 0;*/

	module::Perlin myModule;
	myModule.SetOctaveCount(6.0);
	myModule.SetFrequency(1);
	myModule.SetPersistence(0.5);
	utils::NoiseMap heightMap;
	utils::NoiseMapBuilderPlane heightMapBuilder;
	heightMapBuilder.SetSourceModule(myModule);
	heightMapBuilder.SetDestNoiseMap(heightMap);
	heightMapBuilder.SetDestSize(256, 256);
	heightMapBuilder.SetBounds(6.0, 10.0, 1.0, 5.0);
	heightMapBuilder.Build();

	utils::RendererImage renderer;
	utils::Image image;
	renderer.SetSourceNoiseMap(heightMap);
	renderer.SetDestImage(image);
	renderer.ClearGradient();
	renderer.AddGradientPoint(-1.0000, utils::Color(0, 0, 128, 255)); // deeps
	renderer.AddGradientPoint(-0.2500, utils::Color(0, 0, 255, 255)); // shallow
	renderer.AddGradientPoint(0.0000, utils::Color(0, 128, 255, 255)); // shore
	renderer.AddGradientPoint(0.0625, utils::Color(240, 240, 64, 255)); // sand
	renderer.AddGradientPoint(0.1250, utils::Color(32, 160, 0, 255)); // grass
	renderer.AddGradientPoint(0.3750, utils::Color(224, 224, 0, 255)); // dirt
	renderer.AddGradientPoint(0.7500, utils::Color(128, 128, 128, 255)); // rock
	renderer.AddGradientPoint(1.0000, utils::Color(255, 255, 255, 255)); // snow
	renderer.EnableLight();
	renderer.SetLightContrast(3.0); // Triple the contrast
	renderer.SetLightBrightness(2.0); // Double the brightness
	renderer.SetLightAzimuth(90);
	/*renderer.SetLightColor(noise::utils::Color(128, 0, 0, 255));*/
	renderer.Render();

	utils::WriterBMP writer;
	writer.SetSourceImage(image);
	writer.SetDestFilename("tutorial.bmp");
	writer.WriteDestFile();






	return 0;
}

