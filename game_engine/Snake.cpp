//
// Created by admin on 3/31/2022.
//

#include "Snake.h"

Snake::~Snake() {
}

void Snake::move() {
    for (int i = nodes.size() - 1; i > 0; i--) {
        nodes[i].moveTo(nodes[i - 1].getPosition());
    }
    nodes[0].move(direction);
}

void Snake::setDirection(Coordinate direction) {
    // if the snake is moving in the opposite direction, don't allow it
    if (this->direction.x * direction.x < 0 ||
        this->direction.y * direction.y < 0) {
        return;
    }
    this->direction = direction;
}

GameObject *Snake::getHead() {
    return &nodes[0];
}

GameObject *Snake::getTail() {
    return &nodes[nodes.size() - 1];
}

void Snake::grow() {
    // TH -> TTH -> TBH
    auto headPosition = getHead()->getPosition();
    headPosition = headPosition + direction;
    nodes[0].setSymbol(TYPES::BODY);
    nodes.insert(nodes.begin(), GameObject(headPosition, TYPES::HEAD));
}

std::vector<GameObject> Snake::getNodes() {
    return nodes;

}

bool Snake::collidesWithSelf() {
    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[0].getPosition() == nodes[i].getPosition()) {
            return true;
        }
    }
    return false;
}

