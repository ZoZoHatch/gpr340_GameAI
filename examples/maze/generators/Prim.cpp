#include "Prim.h"
#include "../World.h"
#include <Random.h>


bool Prim::Step(World* world) { 

    auto clearColor = Color::DarkGray;
    auto addedCol = Color::Black;
    auto frontierCol = Color::OrangeRed;
    int halfSize = world->GetSize() / 2;

    /* add random node to frontier */

	if (!initialized) {
    initialized = true;          

    Point2D current = Point2D(Random::Range(-halfSize, halfSize),
                              Random::Range(-halfSize, halfSize));

          world->SetNodeColor(current, frontierCol);
          frontier.push_back(current);
          return true;
	}

	if (frontier.empty()) {
            return false;
    }

    /* add random frontier node to the maze */

    int randFront = Random::Range(0, frontier.size() - 1);
    Point2D current = frontier[randFront];

    frontier.erase(frontier.begin() + randFront);
    world->SetNodeColor(current, addedCol);

    /* break a random wall */

    std::vector<Point2D> potentialWalls;
    Point2D nodeToCheck;

    // North
    nodeToCheck = current + Point2D::UP;
    if (nodeToCheck.y >= -halfSize &&
        world->GetNodeColor(nodeToCheck) == addedCol) {
      potentialWalls.push_back(nodeToCheck);
    }

    // South
    nodeToCheck = current + Point2D::DOWN;
    if (nodeToCheck.y <= halfSize &&
        world->GetNodeColor(nodeToCheck) == addedCol) {
      potentialWalls.push_back(nodeToCheck);
    }

    // East
    nodeToCheck = current + Point2D::RIGHT;
    if (nodeToCheck.x <= halfSize &&
        world->GetNodeColor(nodeToCheck) == addedCol) {
      potentialWalls.push_back(nodeToCheck);
    }

    // West
    nodeToCheck = current + Point2D::LEFT;
    if (nodeToCheck.x >= -halfSize &&
        world->GetNodeColor(nodeToCheck) == addedCol) {
      potentialWalls.push_back(nodeToCheck);
    }

    if (!potentialWalls.empty()) {
      int randWall = Random::Range(0, potentialWalls.size() - 1);
      Point2D wall = potentialWalls[randWall];
      Point2D dir = wall - current;

      if (dir == Point2D::UP) {
        world->SetNorth(current, false);
      } else if (dir == Point2D::DOWN) {
        world->SetSouth(current, false);
      } else if (dir == Point2D::RIGHT) {
        world->SetEast(current, false);
      } else if (dir == Point2D::LEFT) {
        world->SetWest(current, false);
      }
    }
    

    /* add new nodes to the frontier */    

    // North
    nodeToCheck = current + Point2D::UP;
    if (nodeToCheck.y >= -halfSize &&
        world->GetNodeColor(nodeToCheck) == clearColor) {
      frontier.push_back(nodeToCheck);
      world->SetNodeColor(nodeToCheck, frontierCol);
    }

    // South
    nodeToCheck = current + Point2D::DOWN;
    if (nodeToCheck.y <= halfSize &&
        world->GetNodeColor(nodeToCheck) == clearColor) {
      frontier.push_back(nodeToCheck);
      world->SetNodeColor(nodeToCheck, frontierCol);
    }

    // East
    nodeToCheck = current + Point2D::RIGHT;
    if (nodeToCheck.x <= halfSize &&
        world->GetNodeColor(nodeToCheck) == clearColor) {
      frontier.push_back(nodeToCheck);
      world->SetNodeColor(nodeToCheck, frontierCol);
    }

    // West
    nodeToCheck = current + Point2D::LEFT;
    if (nodeToCheck.x >= -halfSize &&
        world->GetNodeColor(nodeToCheck) == clearColor) {
      frontier.push_back(nodeToCheck);
      world->SetNodeColor(nodeToCheck, frontierCol);
    }   

	return true;
}

void Prim::Clear(World* world) { 
  frontier.clear();
  initialized = false;
}