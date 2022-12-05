#include "LorenzoGenerator.h"
#include "../FastNoiseLite.h"
#include "../PerlinNoise.hpp"
#include <iostream>

std::vector<Color32> LorenzoGenerator::Generate(int sideSize, float displacement) {

  std::vector<Color32> cols;
  FastNoiseLite base;
  base.SetFractalOctaves(3);
  base.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
  base.SetFractalType(FastNoiseLite::FractalType_FBm);
  
  FastNoiseLite cellular;
  cellular.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
  cellular.SetFractalOctaves(3);

  for (int i = 0; i < sideSize; i++) {
    for (int j = 0; j < sideSize; j++) {
        
        float height = ((base.GetNoise((float)i, (float)j, displacement * 50) + 1) / 2);
        float humidity = ((cellular.GetNoise((float)j, (float)i, displacement * 50) + 1) / 2);

        auto col = getColor(height, humidity);

        cols.emplace_back(col);
    }
  }

  return cols;
}

std::string LorenzoGenerator::GetName() { return "LORENZOGEN"; }

Color32 LorenzoGenerator::getColor(float height, float humidity) {

    if (height < seaLevel) {
      return Color::DarkTurquoise;
    } else if (height < beachLevel) {
      return Color::Beige;
    } else if (height < grassLevel) {
      return Color::LightGreen;
    } else if (height < forestLevel) {
      return Color::ForestGreen;
    } else if (height < rockLevel) {
      return Color::LightSlateGray;
    } else if (height < snowLevel) {
      return Color::Snow;
    } 

    return Color::HotPink;    
}
