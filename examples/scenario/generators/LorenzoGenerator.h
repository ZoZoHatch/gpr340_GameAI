#ifndef LORENZOGEN_H
#define LORENZOGEN_H

#include "../GeneratorBase.h"

class LorenzoGenerator : public ScenarioGeneratorBase {
 public:
  std::vector<Color32> Generate(int sideSize, float displacement = 0) override;
  std::string GetName() override;
  Color32 getColor(float height, float humidity);

 private:
  float seaLevel = 0.4;
  float beachLevel = 0.5;
  float grassLevel = 0.55;
  float forestLevel = 0.65;
  float rockLevel = 0.8;
  float snowLevel = 0.9;

};

#endif  // LORENZOGEN_H