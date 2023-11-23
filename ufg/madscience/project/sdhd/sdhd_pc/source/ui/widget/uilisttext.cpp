// File Line: 21
// RVA: 0x637990
void __fastcall UFG::UIListText::init(UFG::UIListText *this, UFG::UIList::UIListData *initData)
{
  int v4; // ebp
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::UIScreen *m_screen; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qString result; // [rsp+38h] [rbp-40h] BYREF

  UFG::qString::Set(
    &this->m_initData.m_pathToWidget,
    initData->m_pathToWidget.mData,
    initData->m_pathToWidget.mLength,
    0i64,
    0);
  this->m_initData.m_numSlots = initData->m_numSlots;
  this->m_initData.m_isVertical = initData->m_isVertical;
  this->m_initData.m_canWrap = initData->m_canWrap;
  this->vfptr->update(this);
  v4 = 0;
  while ( v4 < initData->m_numSlots )
  {
    UFG::qString::FormatEx(&result, "%s.menu_slot_%d", initData->m_pathToWidget.mData, (unsigned int)++v4);
    v5 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "UIListText::UISlotText", 0i64, 1u);
    v6 = v5;
    if ( v5 )
    {
      m_screen = this->m_screen;
      v8 = v5 + 1;
      v8->mNext = v8;
      v8[1].mNext = v8;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UISlot::`vftable;
      v6[3].mNext = (UFG::allocator::free_link *)m_screen;
      UFG::qString::qString((UFG::qString *)&v6[4], &result);
      LOWORD(v6[10].mNext) = 0;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UISlotText::`vftable;
    }
    else
    {
      v6 = 0i64;
    }
    (*(void (__fastcall **)(UFG::UIListText *, UFG::allocator::free_link *))this->vfptr->gap8)(this, v6);
    UFG::qString::~qString(&result);
  }
}

