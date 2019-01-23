#ifndef RES_HOLDER_HPP
#define RES_HOLDER_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <cassert>
#include <memory>

enum class Type {PLAYER, NPC, GROUND, VEGETATION, BUILDING, ROAD, STONE, BRIDGE, MISC};


template <typename RES, typename ID>
class ResHolder
{
private:
	std::map<ID, std::unique_ptr<RES>> mTextureMap;

public:
	ResHolder();
	~ResHolder();

	void load(ID id, const std::string &filename);

	RES& get(ID id);
	const RES& get(ID id) const;
};

#include "../methods/res_holder.inl"

#endif