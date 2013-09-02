#include "I_TetrisBlockType.h"
#include "TetrisDataHandle.h"
#include "TetrisGameLayer.h"
void I_TetrisBlockType::init()
{
	TetrisBlockType::init();

	t_count = 4;

	if (! t_childBlockArray)
	{
		CCLog("t_childBlockArray is NULL");
		return;
	}

	TetrisBlock *_block0 = TetrisBlock::create();
	_block0->b_initWithType(0);
	t_childBlockArray->addObject(_block0);
	TetrisGameLayer::getSharedTetrisGameLayer()->blockParentAddChild(_block0);

	TetrisBlock *_block1 = TetrisBlock::create();
	_block1->b_initWithType(1);
	t_childBlockArray->addObject(_block1);
	TetrisGameLayer::getSharedTetrisGameLayer()->blockParentAddChild(_block1);

	TetrisBlock *_block2 = TetrisBlock::create();
	_block2->b_initWithType(2);
	t_childBlockArray->addObject(_block2);
	TetrisGameLayer::getSharedTetrisGameLayer()->blockParentAddChild(_block2);

	TetrisBlock *_block3 = TetrisBlock::create();
	_block3->b_initWithType(3);
	t_childBlockArray->addObject(_block3);
	TetrisGameLayer::getSharedTetrisGameLayer()->blockParentAddChild(_block3);


	int _colum = TetrisDataHandle::getSharedTetrisDataHandle()->h_getTetrisColum() / 2 - 1;
	int _row = TetrisDataHandle::getSharedTetrisDataHandle()->h_getTetrisRow() - 1;

	if(t_typeIndex == 1 || t_typeIndex == 3)//竖向
	{
		t_typeIndex = 1;
	
		TetrisBlock * _bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);
		_bk->b_Update_C_R(_colum, _row + 1/* - 1*/);

		_bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		_bk->b_Update_C_R(_colum, _row + 2);

		_bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(2);
		_bk->b_Update_C_R(_colum, _row);

		_bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		_bk->b_Update_C_R(_colum, _row - 1/* - 1*/);
	}

	if(t_typeIndex == 0 || t_typeIndex == 2)//横向
	{
		t_typeIndex = 0;

		TetrisBlock * _bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);
		_bk->b_leftRotate(90.0f);
		_bk->b_Update_C_R(_colum, _row + 1/* - 1*/);
		

		_bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		_bk->b_leftRotate(90.0f);
		_bk->b_Update_C_R(_colum - 1, _row + 1);
		

		_bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(2);
		_bk->b_leftRotate(90.0f);
		_bk->b_Update_C_R(_colum + 1, _row + 1);
		

		_bk = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		_bk->b_leftRotate(90.0f);
		_bk->b_Update_C_R(_colum + 2, _row + 1);
		

		
	}
	T_updateTetrisStateArray(1);
}

bool I_TetrisBlockType::T_checkDropDown()
{
	if (t_typeIndex == 0)//横向
	{
		TetrisBlock *_block1 = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);
		TetrisBlock *_block2 = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		TetrisBlock *_block3 = (TetrisBlock*)t_childBlockArray->objectAtIndex(2);
		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		if (_block1->b_checkWithDirection(0) && _block2->b_checkWithDirection(0) &&
			_block3->b_checkWithDirection(0) && _block4->b_checkWithDirection(0))
		{
			return true;
		}
	}
	
	if (t_typeIndex == 1)//竖向
	{
		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		return _block4->b_checkWithDirection(0);
	}
	return false;
}

void I_TetrisBlockType::T_dropDown()
{
	for (unsigned int i = 0; i < t_count; ++i)
	{
		TetrisBlock * _block = (TetrisBlock*)t_childBlockArray->objectAtIndex(i);
		_block->b_DropDown();
	}
}

bool I_TetrisBlockType::T_checkLeftMove()
{
	if (t_typeIndex == 0)
	{
		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		return _block4->b_checkWithDirection(1);
	}

	if (t_typeIndex == 1)
	{
		TetrisBlock *_block1 = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);
		TetrisBlock *_block2 = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		TetrisBlock *_block3 = (TetrisBlock*)t_childBlockArray->objectAtIndex(2);
		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		if (_block1->b_checkWithDirection(1) && _block2->b_checkWithDirection(1) &&
			_block3->b_checkWithDirection(1) && _block4->b_checkWithDirection(1))
		{
			return true;
		}
	}
	return false;
}

void I_TetrisBlockType::T_leftMove()
{
	for (unsigned int i = 0; i < t_count; ++i)
	{
		TetrisBlock * _block = (TetrisBlock*)t_childBlockArray->objectAtIndex(i);
		_block->b_LeftMove();
	}
}

bool I_TetrisBlockType::T_checkRightMove()
{
	if (t_typeIndex == 0)
	{
		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		return _block4->b_checkWithDirection(2);
	}

	if (t_typeIndex == 1)
	{
		TetrisBlock *_block1 = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);
		TetrisBlock *_block2 = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		TetrisBlock *_block3 = (TetrisBlock*)t_childBlockArray->objectAtIndex(2);
		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		if (_block1->b_checkWithDirection(2) && _block2->b_checkWithDirection(2) &&
			_block3->b_checkWithDirection(2) && _block4->b_checkWithDirection(2))
		{
			return true;
		}
	}
	return false;
}

void I_TetrisBlockType::T_rightMove()
{
	for (unsigned int i = 0; i < t_count; ++i)
	{
		TetrisBlock *_block = (TetrisBlock*)t_childBlockArray->objectAtIndex(i);
		_block->b_RightMove();
	}
}

void I_TetrisBlockType::T_rotate()
{
	TetrisDataHandle *_sharedHandle = TetrisDataHandle::getSharedTetrisDataHandle();
	int _t_colum = _sharedHandle->h_getTetrisColum();

	TetrisBlock *_block1 = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);

	int _firstBlockColum = _block1->b_getBlockColum();
	int _firstBlockRow = _block1->b_getBlockRow();

	if (t_typeIndex == 1)//转为横向
	{
		if (_firstBlockColum - 1 < 0 || _firstBlockColum + 2 > (_t_colum - 1))
		{
			return;
		}

		int _index_one = _sharedHandle->h_getIndexAt(_firstBlockColum - 1, _firstBlockRow);//左边的位置
		int _index_two = _sharedHandle->h_getIndexAt(_firstBlockColum + 1, _firstBlockRow);//右边的位置
		int _index_three = _sharedHandle->h_getIndexAt(_firstBlockColum + 2, _firstBlockRow);//右边的位置

		if (_sharedHandle->h_getTetrisStateArrayAtIndex(_index_one) ||
			_sharedHandle->h_getTetrisStateArrayAtIndex(_index_two) ||
			_sharedHandle->h_getTetrisStateArrayAtIndex(_index_three))
		{
			return;// 当左边或者右边的state array 返回值都为0时才能旋转
		}

		TetrisBlock *_block1 = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);
		_block1->b_leftRotate(90.0f);

		TetrisBlock *_block2 = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		_block2->b_leftRotate(90.0f);
		_block2->b_Update_C_R(_firstBlockColum - 1, _firstBlockRow);
		

		TetrisBlock *_block3 = (TetrisBlock*)t_childBlockArray->objectAtIndex(2);
		_block3->b_leftRotate(90.0f);
		_block3->b_Update_C_R(_firstBlockColum + 1, _firstBlockRow);
		

		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		_block4->b_leftRotate(90.0f);
		_block4->b_Update_C_R(_firstBlockColum + 2, _firstBlockRow);
		

		t_typeIndex = 0;
		return;
	}
	if (t_typeIndex == 0)
	{
		CCLog("%d, %d", _firstBlockRow, _firstBlockColum);
		if (_firstBlockRow - 2 < 0)
		{
			return;
		}

		int _index_down = _sharedHandle->h_getIndexAt(_firstBlockColum, _firstBlockRow - 2);

		if (_sharedHandle->h_getTetrisStateArrayAtIndex(_index_down))
		{
			return;
		}
		TetrisBlock *_block1 = (TetrisBlock*)t_childBlockArray->objectAtIndex(0);
		_block1->b_rightRotate(90.0f);

		TetrisBlock *_block2 = (TetrisBlock*)t_childBlockArray->objectAtIndex(1);
		_block2->b_rightRotate(90.0f);
		_block2->b_Update_C_R(_firstBlockColum, _firstBlockRow + 1);
		

		TetrisBlock *_block3 = (TetrisBlock*)t_childBlockArray->objectAtIndex(2);
		_block3->b_rightRotate(90.0f);
		_block3->b_Update_C_R(_firstBlockColum, _firstBlockRow - 1);
		

		TetrisBlock *_block4 = (TetrisBlock*)t_childBlockArray->objectAtIndex(3);
		_block4->b_rightRotate(90.0f);
		_block4->b_Update_C_R(_firstBlockColum, _firstBlockRow - 2);
		

		t_typeIndex = 1;
		return;
	}
}

void I_TetrisBlockType::T_updateTetrisStateArray(int _value)
{
	for (unsigned int i = 0; i < t_count; ++i)
	{
		TetrisBlock *_block = (TetrisBlock*)t_childBlockArray->objectAtIndex(i);
		_block->b_UpdateTetrisStateArray(_value);
	}
}
