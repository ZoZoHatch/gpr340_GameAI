#ifndef LORENZOGEN_H
#define LORENZOGEN_H

#include "../GeneratorBase.h"

class LorenzoGenerator : public ScenarioGeneratorBase {
 public:
  std::vector<Color32> Generate(int sideSize, float displacement = 0) override;
  std::string GetName() override;
};

#endif  // LORENZOGEN_H