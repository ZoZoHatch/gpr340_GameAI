#ifndef MOBAGEN_EXAMPLES_MAZE_GENERATORS_PRIMS_H_
#define MOBAGEN_EXAMPLES_MAZE_GENERATORS_PRIMS_H_

#include "../MazeGeneratorBase.h"
#include "Point2D.h"
#include <map>
#include <vector>

class Prim: public MazeGeneratorBase {
 private:
  std::vector<Point2D> frontier;
  bool initialized = false;
  //std::vector<Point2D> getVisitables(World* w, const Point2D& p);
  //std::vector<Point2D> getVisitedNeighbors(World* w, const Point2D& p);

 public:
  Prim() = default;
  std::string GetName() override { return "PrimsLorenzo"; };
  bool Step(World* world) override;
  void Clear(World* world) override;
};

#endif  // MOBAGEN_EXAMPLES_MAZE_GENERATORS_PRIMS_H_
