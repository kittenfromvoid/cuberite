
#pragma once

#include "ItemSeeds.h"
#include "../World.h"





class cItemFoodSeedsHandler :
	public cItemSeedsHandler
{
	typedef cItemSeedsHandler super;

public:
	cItemFoodSeedsHandler(int a_ItemType, FoodInfo a_FoodInfo) :
		cItemSeedsHandler(a_ItemType),
		m_FoodInfo(a_FoodInfo)
	{

	}


	virtual bool IsFood(void) override
	{
		return true;
	}

	virtual FoodInfo GetFoodInfo(const cItem * a_Item) override
	{
		UNUSED(a_Item);
		return m_FoodInfo;
	}

	virtual bool EatItem(cPlayer * a_Player, cItem * a_Item) override
	{
		if (!super::EatItem(a_Player, a_Item))
		{
			return false;
		}

		if (!a_Player->IsGameModeCreative())
		{
			a_Player->GetInventory().RemoveOneEquippedItem();
		}

		return true;
	}

protected:
	FoodInfo m_FoodInfo;

};
