#include "../headers/res_holder.hpp"

template <typename RES, typename ID>
ResHolder<RES, ID>::ResHolder()
{

}

template <typename RES, typename ID>
ResHolder<RES, ID>::~ResHolder()
{

}

template <typename RES, typename ID>
void ResHolder<RES, ID>::load(ID id, const std::string &filename)
{
	std::unique_ptr<RES> texture(new(std::nothrow) RES);
	if(!texture->loadFromFile(filename))
	{
		throw std::runtime_error("ResHolder::load - Failed to load " + filename);
	}

	auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
	assert(inserted.second);
}

template <typename RES, typename ID>
RES& ResHolder<RES, ID>::get(ID id)
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());
	
	return *found->second;
}

template <typename RES, typename ID>
const RES& ResHolder<RES, ID>::get(ID id) const
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());

	return *found->second;
}