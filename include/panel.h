#pragma once 

namespace BDSM
{
    

struct Panel{
	virtual ~Panel(){};
	virtual void Draw() = 0;
};


}