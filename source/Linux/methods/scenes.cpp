#include "../headers/scenes.hpp"

SceneNode::SceneNode()
{

}

void SceneNode::attachChild(sPtr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::sPtr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (sPtr& p) -> bool {
		return p.get() == &node;
	});

	assert(found != mChildren.end());

	sPtr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	
	return result;
}