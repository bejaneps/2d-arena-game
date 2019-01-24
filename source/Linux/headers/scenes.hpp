#ifndef SCENES_HPP
#define SCENES_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>

class SceneNode
{
public:
	typedef std::unique_ptr<SceneNode> sPtr;

public:
	SceneNode();

private:
	void attachChild(sPtr child);
	sPtr detachChild(const SceneNode& node);

private:
	std::vector<sPtr> mChildren;
	SceneNode*		  mParent;
};

#endif